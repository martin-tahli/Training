
#include <stdlib.h>

#include "HumanRace/ClassPaladin.h"
#include "HumanRace/HumanRaceDefines.h"
#include "Defines.h"
#include "ErrorHandler.h"
#include "CheckInput.h"
#include "Utilities.h"
#include "Vector.h"

struct Paladin {
    struct Hero *baseHero;
    int mana;                           // current mana of hero
};

static int FlashOfLight(struct Paladin *self,Vector *team);


static int Revive(struct Paladin *self, Vector *team);

static void regenerateMana(struct Paladin *self);

void menuPaladin(struct Hero** selfs, Vector *attackingTeam ,Vector*enemyTeam);

static int DevotionAura(struct Paladin *self, Vector *team);


struct Paladin *GeneratePaladin(char *const name) {
    struct Paladin *tempPaladin = (struct Paladin *) malloc(sizeof(struct Paladin));
    if (tempPaladin == NULL) {
        printErrorStatus(ERR_ALLOCATE_PALADIN);
    }
    struct Hero *self = initHero();
    SetHeroName(&self, name);
    SetHeroDamage(&self, PALADIN_DAMAGE);
    SetHeroHealth(&self, MAX_PALADIN_HEALTH);
    SetHeroArmor(&self, PALADIN_ARMOR);
    SetHeroClassID(&self, PALADIN);
    SetHeroStatus(&self, ALIVE);
    SetHeroMaxHealth(&self, MAX_PALADIN_HEALTH);
    SetHeroMaxArmor(&self, MAX_PALADIN_ARMOR);
    SetFuncPtrMenu(&self,  &menuPaladin);

    tempPaladin->baseHero = self;
    tempPaladin->mana = MAX_PALADIN_MANA;

    return tempPaladin;
}


void menuPaladin(struct Hero** const selfs, Vector * const attackingTeam ,Vector * const enemyTeam) {

    char *devotionAura = "Devotion Aura";
    char *basicSpellName = "Flash of Light ";
    char *ultimateSpellName = "Revive"; //not working

    struct Paladin * self = (struct Paladin *) selfs;

    printf("\nWould you like to\n1 - deal damage\n2 - buff/heal allies?\n");
    int choice = validateIntegerInput(1, 2);

    if (choice == 1) {   // deal damage to enemy
        printTeam(enemyTeam);
        int enemyID = chooseEnemy(enemyTeam);
        struct Hero ** targetEnemy = vectorGet(enemyTeam, enemyID);
        receiveDamage(selfs, targetEnemy, PALADIN_DAMAGE);
        regenerateMana(self);
        return;
    }
    // if we get here it means choice is 2

    printf("\n1 - %s\n2 - %s\n3 - %s\n", devotionAura, basicSpellName, ultimateSpellName);

    while (1) {
        choice = validateIntegerInput(1, 3);

        switch(choice){
            case PALADIN_ARMOR_BUFF:
                if (DevotionAura(self, attackingTeam)== NOT_ENOUGH_MANA) continue;
                break;
            case FLASH_LIGHT:
                if (FlashOfLight(self, attackingTeam) == NOT_ENOUGH_MANA) continue;
                break;
            case REVIVE:
                if (Revive(self,  attackingTeam) == 0) {
                    continue;
                }
                break;
            default:
                break;
        }
        regenerateMana(self);
        return ;
    }
}


static int DevotionAura(struct Paladin * const self, Vector * const team) {

    printTeam(team);
    //  selecting the enemy here, this func returns their id as int
    int allyID = chooseAliveAlly(team);
    //  getting the enemy by their ID from above
    struct Hero ** targetAlly = vectorGet(team, allyID);

    if (self->mana < DEVOTION_AURA_MANA_COST) {
        printf("\nInsufficient mana\n");
        return NOT_ENOUGH_MANA;
    }

    int heroArmor = GetHeroArmor(*targetAlly);
    int maxHeroArmor = GetHeroMaxArmor(*targetAlly);

    if (heroArmor + DEVOTION_AURA_BUFF >= maxHeroArmor) {
        SetHeroArmor(targetAlly, MAX_PALADIN_ARMOR);
    }

    self->mana -= DEVOTION_AURA_MANA_COST;
    printf("\nPaladin %s dealt Devotion Aura spell with %d Armor buff !\n", GetHeroName(self->baseHero),
           DEVOTION_AURA_BUFF);


    return SUCCESSFULL_CAST;
}


static int FlashOfLight(struct Paladin * const self, Vector* const team) {

    printTeam(team);
    //  selecting the enemy here, this func returns their id as int
    int allyID = chooseAliveAlly(team);
    //  getting the enemy by their ID from above
    struct Hero ** targetAlly = vectorGet(team, allyID);

    if (self->mana < FLASH_LIGHT_MANA_COST) {
        printf("\nInsufficient mana\n");
        return NOT_ENOUGH_MANA;  //fix return 0 later
    }
    int targetHeroHP = GetHeroHealth(*targetAlly);
    int targetHeroMaxHP = GetHeroMaxHealth(*targetAlly);

    if (targetHeroHP + FLASH_LIGHT_HEAL >= targetHeroMaxHP) {
        SetHeroHealth(targetAlly, targetHeroMaxHP);
    }

    SetHeroHealth(targetAlly, targetHeroHP + FLASH_LIGHT_HEAL);

    self->mana -= FLASH_LIGHT_MANA_COST;
    printf("\nPaladin %s used Flash of Light spell to heal %d!\n", GetHeroName(self->baseHero), FLASH_LIGHT_HEAL);

    return SUCCESSFULL_CAST;
}


static int Revive(struct Paladin* const self, Vector* const team) {

    int isDeadAlly = false;

    if (self->mana < REVIVE_MANA_COST) {
        printf("\nInsufficient mana\n");
        return NOT_ENOUGH_MANA;  //fix return 0 later
    }

    int teamSize = vectorGetSize(team);
    struct Hero **targetHero;

    // loop to see if we have anyone dead on our team
    for (int heroIndx = 0; heroIndx < teamSize; heroIndx++) {
        targetHero = vectorGet(team, heroIndx); //set current enemy hero data
        int HeroStatus = GetHeroStatus(*targetHero);
        if (HeroStatus != DEAD) {
            continue;
        }
        isDeadAlly = true;
        break;
    }
    if (!isDeadAlly) {
        return NO_DEAD_ALLY;
    }

    int targetID = chooseDeadAlly(team);

    targetHero = vectorGet(team, targetID);// Targeted by player enemy hero.
    SetHeroHealth(targetHero, REVIVE_HEALTH);
    SetHeroStatus(targetHero, ALIVE);
    printf("\n%s was revived with %dhp!\n", GetHeroName(*targetHero), REVIVE_HEALTH);

    self->mana -= REVIVE_MANA_COST;

    return SUCCESSFULL_CAST;
}

static void regenerateMana(struct Paladin* const self) {
    if (self->mana + PALADIN_BASE_MANA_REGEN >= MAX_PALADIN_MANA) {
        printf("\nPaladin %s regenerated its mana to max!\n", GetHeroName(self->baseHero));
        self->mana = MAX_PALADIN_MANA;
        return;
    }
    self->mana += PALADIN_BASE_MANA_REGEN;
}
