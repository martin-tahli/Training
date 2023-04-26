#ifndef STARCRAFT_CARRIER_H
#define STARCRAFT_CARRIER_H


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "UnitTypesStructuresH/ProtossUnitType.h"
#include "Defines.h"
#include "ErrorHandler.h"

/**
 * Child struct used to define a Carrier Unit. Contains inherited protossUnit structure.
 */
struct Carrier {
    struct protossUnit ProtossUnit;
};

struct Carrier *newCarrierUnit(void);

int16_t getDmgInterceptor(struct Carrier *self);

void damageReceivedCarrier(struct Carrier *currentUnit, int16_t incomingDamage);

int16_t carrierAttack(struct Carrier *self, int16_t enemyHP);

int16_t getCountInterceptors(struct Carrier *self);

#endif //STARCRAFT_CARRIER_H
