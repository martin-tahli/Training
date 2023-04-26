#ifndef STARCRAFT_PHOENIX_H
#define STARCRAFT_PHOENIX_H


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "UnitTypesStructuresH/ProtossUnitType.h"
#include "Defines.h"
#include "ErrorHandler.h"


/**
 * Child struct used to define a Phoenix Unit. Contains inherited protossUnit structure.
 */
struct Phoenix {
    struct protossUnit ProtossUnit;

};

struct Phoenix *newPhoenixUnit(void);

void regenerateShieldPhoenix(struct Phoenix *self);

int16_t phoenixAttack(struct Phoenix *self);

void damageReceivedPhoenix(struct Phoenix *currentUnit, int16_t incomingDamage);

#endif //STARCRAFT_PHOENIX_H
