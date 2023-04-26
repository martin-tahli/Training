#include "WarUnitsH/Mutalisk.h"

/**
 * New Mutalisk generator
 * @return pointer to the new Mutalisk
 */
struct Mutalisk *newMutalisk(void) {

    struct Mutalisk *self = (struct Mutalisk *) malloc(sizeof(struct Mutalisk));
    if (self == NULL) {
        printErrorStatus(ERR_ALLOCATE_MUTALISK);
        return FALSE;
    }
    self->zergUnit.BasicUnit.unitType = MUTALISK;     //4
    self->zergUnit.BasicUnit.health = MUTALISK_HEALTH;
    self->zergUnit.BasicUnit.damage = MUTALISK_DAMAGE;
    self->regenRate = MUTALISK_HEALTH_REGEN;
    self->zergUnit.BasicUnit.raceType = ZERG;

    return self;
}

/**
 * This function is for the Mutalisk to regenerate its health.
 * @param self Mutalisk pointer to the current Mutalisk.
 */
void regenerateHealthMutalisk(struct Mutalisk *self) {
    if (self->zergUnit.BasicUnit.health + self->regenRate >= MUTALISK_HEALTH) {
        self->zergUnit.BasicUnit.health = MUTALISK_HEALTH;
        return;
    }
    self->zergUnit.BasicUnit.health += self->regenRate;

}

/**
 * This function gets the Mutalisk daamge and regenerates its health.
 * @param self Mutalisk pointer to the current Mutalisk.
 * @return The Mutalisk's damage.
 */
int16_t mutaliskAttack(struct Mutalisk *self) {
    regenerateHealthMutalisk(self);
    return self->zergUnit.BasicUnit.damage;
}

/**
 * This function processes the damage the Mutalisk receives.
 * @param self
 * @param damage
 */
void damageTakenMutalisk(struct Mutalisk *self, int16_t damage) {
    self->zergUnit.BasicUnit.health -= damage;
}