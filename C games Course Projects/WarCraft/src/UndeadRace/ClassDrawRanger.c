
#include <stdlib.h>

#include "UndeadRace/UndeadRaceDefines.h"
#include "Defines.h"
#include "ErrorHandler.h"
#include "CheckInput.h"
#include "Vector.h"
#include "Utilities.h"

struct DrawRanger {
    struct Hero *baseHero;
    int mana;
};

/**
 * This function does the Draw Ranger black arrows spell.
 * @return the damage of black arrows spell.
 */
static int blackArrowsDrawRanger(struct Hero **selfs, struct Hero **target, Vector* enemyTeam);


/**
 * This function does the Draw Ranger Life drain spell
 * @return the life drain damage if enough mana.
 */
static int lifeDrainDrawRanger(struct Hero**  selfs,struct Hero** target);


/**
 * This function regenerate Draw Ranger's mana.
 *
 */
static void regenerateMana(struct DrawRanger *self);


/**
 * This function lets the player to chose an Draw Ranger actions.
 * @return the chosen action.
 */
void menuDrawRanger(struct Hero** selfs, __attribute__ ((unused))Vector *attackingTeam ,Vector*enemyTeam);

/**
 * This function generate Draw Ranger unit and set all of its parameters.
 * @return a pointer reference to the object.
 */
struct DrawRanger *GenerateDrawRanger(char *const name) {
    struct DrawRanger *tempDrawRanger = (struct DrawRanger *) malloc(sizeof(struct DrawRanger));
    if (tempDrawRanger == NULL) {
        printErrorStatus(ERR_ALLOCATE_DRAW_RANGER);
    }
    struct Hero *self = initHero();

    SetHeroName(&self, name);
    SetHeroDamage(&self, DRAW_RANGER_DAMAGE);
    SetHeroHealth(&self, MAX_DRAW_RANGER_HEALTH);
    SetHeroArmor(&self, DRAW_RANGER_ARMOR);
    SetHeroClassID(&self, DRAW_RANGER);
    SetHeroStatus(&self, ALIVE);
    SetHeroMaxHealth(&self, MAX_DRAW_RANGER_HEALTH);
    SetHeroMaxArmor(&self, MAX_DRAW_RANGER_ARMOR);
    SetFuncPtrMenu(&self,  &menuDrawRanger);

    tempDrawRanger->baseHero = self;
    tempDrawRanger->mana = MAX_DRAW_RANGER_MANA;

    return tempDrawRanger;
}


void menuDrawRanger(struct Hero** const  selfs,__attribute__ ((unused)) Vector * const attackingTeam ,Vector* const enemyTeam) {



    char *basicAttackName = "Basic attack, normal damage";
    char *basicSpellName = "Black arrows spell";
    char *ultimateSpellName = "Life drain spell";

    struct DrawRanger * self = (struct DrawRanger *) selfs;

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
            case DRAW_RANGER_NORMAL_DAMAGE:
                receiveDamage(selfs, targetEnemy, DRAW_RANGER_DAMAGE);
                break;
            case BLACK_ARROWS:
                if (blackArrowsDrawRanger(selfs, targetEnemy,  enemyTeam)==NOT_ENOUGH_MANA) continue;
                break;
            case  LIFE_DRAIN:
                if ( lifeDrainDrawRanger( selfs,targetEnemy) == NOT_ENOUGH_MANA ) continue;
                break;
            default:
                break;
        }
        regenerateMana(self);
        return;
    }
}

static int blackArrowsDrawRanger(struct Hero ** const selfs, struct Hero ** target, Vector* const enemyTeam) {
    struct DrawRanger * self = (struct DrawRanger *) selfs;
    int targetID;

    if (self->mana >= BLACK_ARROWS_MANA_COST)
    {
        self->mana-=BLACK_ARROWS_MANA_COST;
        receiveDamage(selfs, target, BLACK_ARROWS_DAMAGE);

        printf("\nChoose second target:\n");
        printTeam(enemyTeam);
        targetID = chooseEnemy(enemyTeam);
        target = vectorGet(enemyTeam, targetID);

        receiveDamage(selfs, target, BLACK_ARROWS_DAMAGE);
        return SUCCESSFULL_CAST;
    }
    else {
        printf("\nDraw Ranger %s doesn't have enough mana!\n", GetHeroName(self->baseHero));
        return NOT_ENOUGH_MANA;
    }

}


static int lifeDrainDrawRanger(struct Hero** const selfs, struct Hero** target) {

    struct DrawRanger * self = (struct DrawRanger *) selfs;
    int currentHealth = GetHeroHealth( *selfs);

    if(self->mana >= LIFE_DRAIN_MANA_COST) {
        if ( currentHealth + LIFE_DRAIN_HEAL < MAX_DRAW_RANGER_HEALTH) {

            SetHeroHealth( selfs, (LIFE_DRAIN_HEAL + currentHealth));

            printf("\nDraw Ranger %s regenerated its health with %d points!\n", GetHeroName(self->baseHero), LIFE_DRAIN_HEAL);
        }
        else {
            SetHeroHealth( selfs, MAX_DRAW_RANGER_HEALTH);

            printf("\nDraw Ranger %s regenerated its health to maximum! \n", GetHeroName(self->baseHero));
        }

        receiveDamage(selfs, target, LIFE_DRAIN_DAMAGE);

        self->mana-=LIFE_DRAIN_MANA_COST;
       return SUCCESSFULL_CAST;
    }
    else {
        printf("\nDraw Ranger %s doesn't have enough mana!\n", GetHeroName(self->baseHero));
        return NOT_ENOUGH_MANA;
    }
}


static void regenerateMana(struct DrawRanger* const self) {
    if (self->mana + DRAW_RANGER_BASE_MANA_REGEN >= MAX_DRAW_RANGER_MANA) {
        self->mana = MAX_DRAW_RANGER_MANA;
        printf("\nDraw Ranger %s regenerated its mana to max!\n", GetHeroName(self->baseHero));
        return;
    }
    self->mana += DRAW_RANGER_BASE_MANA_REGEN;
    printf("\nDraw Ranger %s  regenerated its mana + %d!\n", GetHeroName(self->baseHero),DRAW_RANGER_BASE_MANA_REGEN);
}
