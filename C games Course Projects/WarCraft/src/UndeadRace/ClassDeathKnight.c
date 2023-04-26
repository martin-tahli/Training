
#include <stdlib.h>
#include "UndeadRace/ClassDeathKnight.h"
#include "UndeadRace/UndeadRaceDefines.h"
#include "Defines.h"
#include "ErrorHandler.h"
#include "CheckInput.h"
#include "Utilities.h"

struct DeathKnight {
    struct Hero *baseHero;
    int mana;

};
/**
 *
 * @param selfs
 * @param target
 * @return
 */
static int DeathCoil(struct Hero **selfs, struct Hero **target);
/**
 *
 * @param selfs
 * @param target
 * @return
 */
static int AnimateDead(struct Hero **selfs, struct Hero **target);
/**
 *
 * @param self
 */
static void regenerateMana(struct DeathKnight *self);

void menuDK(struct Hero** selfs, __attribute__ ((unused))Vector *attackingTeam, Vector*enemyTeam);


struct DeathKnight *GenerateDeathKnight(char *const name) {
    struct DeathKnight *tempDeathKnight = (struct DeathKnight *) malloc(sizeof(struct DeathKnight));
    if (tempDeathKnight == NULL) {
        printErrorStatus(ERR_ALLOCATE_DEATH_KNIGHT);
    }
    struct Hero *self = initHero();

    SetHeroName(&self, name);
    SetHeroDamage(&self, DEATH_KNIGHT_DAMAGE);
    SetHeroHealth(&self, MAX_DEATH_KNIGHT_HEALTH);
    SetHeroArmor(&self, DEATH_KNIGHT_ARMOR);
    SetHeroClassID(&self, DEATH_KNIGHT);
    SetHeroStatus(&self, ALIVE);
    SetHeroMaxHealth(&self, MAX_DEATH_KNIGHT_HEALTH);
    SetHeroMaxArmor(&self, MAX_DEATH_KNIGHT_ARMOR);
    SetFuncPtrMenu(&self,  &menuDK);

    tempDeathKnight->baseHero = self;
    tempDeathKnight->mana = MAX_DEATH_KNIGHT_MANA;

    return tempDeathKnight;
}

void menuDK(struct Hero** const selfs, __attribute__ ((unused))Vector * const attackingTeam ,Vector* const enemyTeam) {

    char *normalAttack = "Basic attack";
    char *basicSpellName = "Death Coil";
    char *ultimateSpellName = "Animate Dead"; //not working

    struct DeathKnight * self = (struct DeathKnight *) selfs;

    printTeam(enemyTeam);
    //  selecting the enemy here, this func returns their id as int
    int enemyID = chooseEnemy(enemyTeam);
    //  getting the enemy by their ID from above
    struct Hero ** targetEnemy = vectorGet(enemyTeam, enemyID);

    printf("1 - %s\n2 - %s\n3 - %s\n", normalAttack, basicSpellName, ultimateSpellName);

    while (1) {
        fflush(stdin);
        int choice = validateIntegerInput(1, 3);

        switch(choice){
            case DEATH_KNIGHT_NORMAL_DAMAGE:
                receiveDamage(selfs, targetEnemy, DEATH_KNIGHT_DAMAGE);
                break;
            case DEATH_COIL:
                if (DeathCoil(selfs, targetEnemy)==NOT_ENOUGH_MANA) continue;
                break;
            case ANIMATED_DEAD:
                if (AnimateDead(selfs, targetEnemy) == NOT_ENOUGH_MANA ) continue;
                break;
            default:
                break;
        }
        regenerateMana(self);
        return;
    }
}

static int DeathCoil(struct Hero ** const selfs, struct Hero ** const target) {

    struct DeathKnight * self = (struct DeathKnight *) selfs;

    if (self->mana >= DEATH_COIL_MANA_COST) {

        self->mana -= DEATH_COIL_MANA_COST;

        receiveDamage(selfs, target, DEATH_COIL_DAMAGE);
    } else {
        printf("\nInsufficient mana\n");
        return NOT_ENOUGH_MANA;
    }
    return SUCCESSFULL_CAST;
}


static int AnimateDead(struct Hero ** const selfs, struct Hero ** const target) {

    struct DeathKnight * self = (struct DeathKnight *) selfs;
    int dmg=GHOUL_DAMAGE*SPAWN_GHOUL;

    if (self->mana >= ANIMATE_DEAD_MANA_COST) {

        self->mana -= ANIMATE_DEAD_MANA_COST;

        receiveDamage(selfs, target, dmg);
    } else {
        printf("\nInsufficient mana\n");
        return NOT_ENOUGH_MANA;
    }
    return SUCCESSFULL_CAST;
}


static void regenerateMana(struct DeathKnight * const self) {
    if (self->mana + DEATH_KNIGHT_BASE_MANA_REGEN >= MAX_DEATH_KNIGHT_MANA) {
        printf("\nDeath Knight  %s regenerated its mana to max!\n", GetHeroName(self->baseHero));
        self->mana = MAX_DEATH_KNIGHT_MANA;
        return;
    }
    self->mana += DEATH_KNIGHT_BASE_MANA_REGEN;
}
