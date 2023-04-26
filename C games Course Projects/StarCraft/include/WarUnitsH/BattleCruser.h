#ifndef STARCRAFT_BATTLECRUSER_H
#define STARCRAFT_BATTLECRUSER_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

#include "WarUnitsH/BattleCruser.h"
#include "Defines.h"
#include "UnitTypesStructuresH/TerranUnitType.h"
#include "ErrorHandler.h"


/**
 * Child struct used to define a Carrier Unit. Contains inherited protossUnit structure.
 */
struct BattleCruser {
    struct terranUnit terranUnit ;
};

struct BattleCruser *newBattleCruserUnit(void);

int16_t battleCruserAttack(struct BattleCruser *self);

void damageReceivedBattleCruser(struct BattleCruser* currentTarget, int16_t damageReceived);

#endif //STARCRAFT_BATTLECRUSER_H
