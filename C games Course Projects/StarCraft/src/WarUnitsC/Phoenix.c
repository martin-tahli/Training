#include "WarUnitsH/Phoenix.h"

/**
 * This function gets the Phoenix attack damage.
 * @param self Phoenix pointer to the current Phoenix.
 * @return the damage of the Phoenix.
 */
int16_t phoenixAttack(struct Phoenix *self) {
    regenerateShieldPhoenix(self);
    return self->ProtossUnit.BasicUnit.damage;
}

/**
 * Creates a Phoenix Unit with a predefined amount of members.
 * @return A pointer to a Phoenix stored in the memory.
 */
struct Phoenix *newPhoenixUnit(void) {

    struct Phoenix *self = (struct Phoenix *) malloc(sizeof(struct Phoenix));
    if (self == NULL) {
        printErrorStatus(ERR_ALLOCATE_PHOENIX);
        return FALSE;
    }
    self->ProtossUnit.BasicUnit.health = PHOENIX_HEALTH;
    self->ProtossUnit.BasicUnit.damage = PHOENIX_DAMAGE;
    self->ProtossUnit.BasicUnit.unitType = PHOENIX;
    self->ProtossUnit.BasicUnit.raceType = PROTOSS;
    self->ProtossUnit.shield = PHOENIX_SHIELD;

    return self;
}

/**
 * Function is used to increment the shield of current Phoenix unit,
 * if it exceeds maximum shield shield  we set member to maximum shield value.
 * @param Phoenix pointer pointing current instance of type Phoenix.
 */
void regenerateShieldPhoenix(struct Phoenix *self) {
    if (self->ProtossUnit.shield + PHOENIX_SHIELD_REGENERATE_RATE >= PHOENIX_SHIELD) {
        self->ProtossUnit.shield = PHOENIX_SHIELD;
    } else {
        self->ProtossUnit.shield += PHOENIX_SHIELD_REGENERATE_RATE;
    }
}

/**
 * This function processes the Phoenix getting hurt.
 * @param self Phoenix pointer to the current Phoenix.
 * @param incomingDamage the damage that the Phoenix is going to receive.
 */
void damageReceivedPhoenix(struct Phoenix *self, int16_t incomingDamage) {

    if (self->ProtossUnit.shield > incomingDamage) {
        self->ProtossUnit.shield -= incomingDamage;
        return;
    } else if (self->ProtossUnit.shield == incomingDamage) {
        self->ProtossUnit.shield = 0;
        return;
    }
    int16_t damageCarryOver = incomingDamage - (self)->ProtossUnit.shield;
    self->ProtossUnit.shield = 0;
    self->ProtossUnit.BasicUnit.health -= damageCarryOver;

}
