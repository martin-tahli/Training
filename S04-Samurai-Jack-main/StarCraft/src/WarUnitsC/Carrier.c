#include "WarUnitsH/Carrier.h"


/**
 * Creates a Carrier Unit with a predefined amount of members.
 * @return A pointer to a Carrier stored in the memory.
 */
struct Carrier *newCarrierUnit(void) {

    struct Carrier *self = (struct Carrier *) malloc(sizeof(struct Carrier));
    if (self == NULL) {
        printErrorStatus(ERR_ALLOCATE_CARRIER);
        return FALSE;
    }
    self->ProtossUnit.BasicUnit.unitType = CARRIER;
    self->ProtossUnit.BasicUnit.health = CARRIER_HEALTH;
    self->ProtossUnit.BasicUnit.damage = CARRIER_DAMAGE;
    self->ProtossUnit.shield = CARRIER_SHIELD;
    self->ProtossUnit.BasicUnit.raceType = PROTOSS;

    return self;
}

/**
 * Function is used to increment the shield of current Carrier unit,
 * if it exceeds maximum shield  we set the member with maximum shield value.
 * @param Carrier pointer pointing current instance of type Carrier.
 */
void regenerateShieldCarrier(struct Carrier *self) {
    if (self->ProtossUnit.shield + CARRIER_SHIELD_REGENERATE_RATE >= CARRIER_SHIELD)
        self->ProtossUnit.shield = CARRIER_SHIELD;
    else
        self->ProtossUnit.shield += CARRIER_SHIELD_REGENERATE_RATE;
}


/** Check if health of carrier is maximum or not.
* @param Carrier pointer pointing current instance of type Carrier.
* @return Returns max interceptors if health is maximum,           TO DO
* Returns damage that carrier can do.                      TO DO
*/
int16_t getCountInterceptors(struct Carrier *self) { // TO DO Check const.
    regenerateShieldCarrier(self);
    if (self->ProtossUnit.BasicUnit.health != CARRIER_HEALTH)
        return DAMAGED_STATUS_INTERCEPTORS;
    return MAX_INTERCEPTORS;
}

/**
 * This function gets the interceptor's damage.
 * @param self Carrier pointer to the current Carrier.
 * @return the damage of the interceptor
 */
int16_t getDmgInterceptor(struct Carrier *self) {

    return self->ProtossUnit.BasicUnit.damage;
}

/**
 * This function calculates and processes the damage the Carrier Received.
 * @param self Carrier pointer to the current Carrier.
 * @param incomingDamage the damage that the Carrier receives.
 */
void damageReceivedCarrier(struct Carrier *self, int16_t incomingDamage) {

    if (self->ProtossUnit.shield > incomingDamage) {
        self->ProtossUnit.shield -= incomingDamage;
        return;
    } else if (self->ProtossUnit.shield == incomingDamage) {
        self->ProtossUnit.shield = 0;
        return;
    }
    int16_t damageCarryOver = incomingDamage - self->ProtossUnit.shield;
    self->ProtossUnit.shield = 0;
    self->ProtossUnit.BasicUnit.health -= damageCarryOver;

}
