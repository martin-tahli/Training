#ifndef STARCRAFT_MUTALISK_H
#define STARCRAFT_MUTALISK_H


#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

#include "Defines.h"
#include "UnitTypesStructuresH/BasicUnitType.h"
#include "UnitTypesStructuresH/ZergUnitType.h"
#include "ErrorHandler.h"


struct Mutalisk {
    struct ZergUnit zergUnit;
    int16_t regenRate;
};

struct Mutalisk *newMutalisk(void);

void damageTakenMutalisk(struct Mutalisk *currentTarget, int16_t damage);

int16_t mutaliskAttack(struct Mutalisk *self);

#endif //STARCRAFT_MUTALISK_H
