#include "WarUnitsH/Viking.h"

/**
 * Creates a Viking Unit with a predefined amount of members.
 * @return A pointer to a Viking stored in the memory.
 */
struct Viking *newVikingUnit(void) {

    struct Viking *self = (struct Viking *) malloc(sizeof(struct Viking));
    if (self == NULL) {
        printErrorStatus(ERR_ALLOCATE_VIKING);
        return FALSE;
    }
    self->TerranUnit.BasicUnit.health = VIKING_HEALTH;
    self->TerranUnit.BasicUnit.damage = VIKING_DAMAGE;
    self->TerranUnit.BasicUnit.unitType = VIKING;
    self->TerranUnit.BasicUnit.raceType = TERRAN;


    return self;
}

/**
 * Check if enemy type unit is Phoenix.
 * @param self pointer pointing current instance of type Viking.
 * @param enemyUnitType number that identifies enemy unit.
 * @return Returns double damage if enemy is Phoenix. Return normal damage if enemy type is not Phoenix.
 */
int16_t vikingAttack(struct Viking *self,  int16_t enemyUnitType) {
    if (enemyUnitType == PHOENIX)
        return self->TerranUnit.BasicUnit.damage * 2; //We double damage dealt if we attack enemy Phoenix.
    return self->TerranUnit.BasicUnit.damage;
}

/**
 * This function processes the Viking getting hurt.
 * @param self
 * @param damageReceived
 */
void damageReceivedViking(struct Viking* self, int16_t damageReceived) {
    self->TerranUnit.BasicUnit.health -= damageReceived;
}
