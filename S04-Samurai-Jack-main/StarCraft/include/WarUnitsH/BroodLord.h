#ifndef STARCRAFT_BROODLORD_H
#define STARCRAFT_BROODLORD_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "UnitTypesStructuresH/BasicUnitType.h"
#include "UnitTypesStructuresH/ZergUnitType.h"
#include "Defines.h"
#include "ErrorHandler.h"


struct BroodLord {
    struct ZergUnit zergUnit;
    int16_t broodlingCounter;
    int16_t armor;
};

struct BroodLord *newBroodLord(void);

void damageReceivedBroodLord(struct BroodLord *currentUnit, int16_t incomingDamage);

int16_t broodLordAttack(struct BroodLord *self);

#endif //STARCRAFT_BROODLORD_H
