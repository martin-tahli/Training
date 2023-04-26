#ifndef STARCRAFT_VIKING_H
#define STARCRAFT_VIKING_H


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Defines.h"
#include "UnitTypesStructuresH/TerranUnitType.h"
#include "ErrorHandler.h"


/**
 * Child struct used to define a Carrier Unit. Contains inherited protossUnit structure.
 */
struct Viking {
    struct terranUnit TerranUnit;
};


struct Viking *newVikingUnit(void);

int16_t vikingAttack(struct Viking *self, int16_t enemyUnitType);

void damageReceivedViking(struct Viking *currentTarget, int16_t damageReceived);

#endif //STARCRAFT_VIKING_H
