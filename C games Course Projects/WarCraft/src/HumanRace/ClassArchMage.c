
#include <stdlib.h>

#include "HumanRace/ClassArchMage.h"
#include "HumanRace/HumanRaceDefines.h"
#include "Defines.h"

#include "ErrorHandler.h"
#include "Vector.h"
#include "Utilities.h"
#include "CheckInput.h"

struct ArchMage {
    struct Hero *baseHero;
    int mana;     // current mana of hero
};

void menuArchMage(struct Hero** selfs,__attribute__ ((unused)) Vector *attackingTeam ,Vector*enemyTeam);
static void regenerateMana(struct ArchMage*  self);
static int SummonWaterElemental(struct Hero **selfs, struct Hero **target);
static void ManaBlast(struct Hero **selfs, struct Hero **target);

struct ArchMage *GenerateArchMage(char* const name) {
    struct ArchMage *tempArchMage = (struct ArchMage*)malloc(sizeof (struct ArchMage));
    if ( tempArchMage == NULL)
    {
        printErrorStatus(ERR_ALLOCATE_ARCHMAGE);
    }

    struct Hero *self = initHero();
    SetHeroName( &self, name);
    SetHeroDamage(&self,ARCH_MAGE_DAMAGE);
    SetHeroHealth(&self, MAX_ARCH_MAGE_HEALTH);
    SetHeroArmor(&self, ARCH_MAGE_ARMOR);
    SetHeroClassID(&self, ARCH_MAGE);
    SetHeroStatus(&self, ALIVE);
    SetHeroMaxHealth(&self, MAX_ARCH_MAGE_HEALTH);
    SetHeroMaxArmor(&self, MAX_ARCH_MAGE_ARMOR);
    SetFuncPtrMenu(&self, &menuArchMage);


    tempArchMage->baseHero = self;
    tempArchMage->mana = MAX_ARCH_MAGE_MANA;

    return tempArchMage;
}

void menuArchMage(struct Hero** const selfs, __attribute__ ((unused))Vector * const attackingTeam ,Vector* const enemyTeam) {

  //  dummyHandle(attackingTeam);

//// the next two rows are used for preventing the cmake helpers. they don't have meaning , the idea of them is to use Vector attacking team for future features
//    struct Hero ** dummyTarget = vectorGet(attackingTeam, 0);
//// dummy func to prevent error
//    receiveDamage(dummyTarget,dummyTarget,0);

    char *basicAttackName = "Basic attack, normal damage";
    char *basicSpellName = "Summon Water Elemental";
    char *ultimateSpellName = "Mana blast";

    struct ArchMage * self = (struct ArchMage *) selfs;

    printTeam(enemyTeam);
    //  selecting the enemy here, this func returns their id as int
    int enemyID = chooseEnemy(enemyTeam);
    //  getting the enemy by their ID from above
    struct Hero ** targetEnemy = vectorGet(enemyTeam, enemyID);

    printf("1 - %s\n2 - %s\n3 - %s\n", basicAttackName, basicSpellName, ultimateSpellName);

    while (1) {
        fflush(stdin);
        int choice = validateIntegerInput(1, 3);

        switch(choice){
            case ARCH_MAGE_NORMAL_DAMAGE:
                receiveDamage(selfs, targetEnemy, ARCH_MAGE_DAMAGE);
                //regen mana here
                break;
            case SUMMON_WATER_ELEMENTAL:
                if (SummonWaterElemental(selfs, targetEnemy)==NOT_ENOUGH_MANA) continue;
                break;
            case  MANA_BLAST:
                ManaBlast(selfs, targetEnemy);
                break;
            default:
                break;
        }
        regenerateMana(self);
        return;
    }
}

static int SummonWaterElemental(struct Hero ** const selfs, struct Hero ** const target) {

    struct ArchMage * self = (struct ArchMage *) selfs;
    int dmg=WATER_ELEMENTAL_DAMAGE * WATER_ELEMENTAL_COUNT;

    if (self->mana >= SUMMON_WATER_ELEMENTAL_MANA_COST) {

        self->mana -= SUMMON_WATER_ELEMENTAL_MANA_COST;

        receiveDamage(selfs, target, dmg);
    } else {
        printf("\nInsufficient mana\n");
        return NOT_ENOUGH_MANA;  //fix return 0 later
    }
    return SUCCESSFULL_CAST;

}

static void ManaBlast(struct Hero ** const selfs, struct Hero ** const target) {

    struct ArchMage * self = (struct ArchMage *) selfs;
    int currentMana = self->mana;

    // this spell will always do half of current mana as dmg
    int dmg = currentMana / 2;

    receiveDamage(selfs, target, dmg);
    self->mana -= dmg;

    // we regen mana twice as per the special ability
    regenerateMana(self);
}

static void regenerateMana(struct ArchMage* const self) {
    if (self->mana + ARCH_MAGE_BASE_MANA_REGEN >= MAX_ARCH_MAGE_MANA) {
        self->mana = MAX_ARCH_MAGE_MANA;
        printf("\nArch Mage %s regenerated its mana to max!\n", GetHeroName(self->baseHero));
        return;
    }
    self->mana += ARCH_MAGE_BASE_MANA_REGEN;
    printf("\nArch Mage %s  regenerated its mana + %d!\n", GetHeroName(self->baseHero),ARCH_MAGE_BASE_MANA_REGEN);
}