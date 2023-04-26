#ifndef STARCRAFT_PROTOSSUNITS_H
#define STARCRAFT_PROTOSSUNITS_H
#include <stdint.h>
#include "UnitTypesStructuresH/BasicUnitType.h"

struct protossUnit {
    struct basicUnit BasicUnit;
    int16_t shield;
};


int getProtossUnitDamage(struct protossUnit **CurrentProtossUnit);

int getProtossUnitHealth(struct protossUnit **CurrentProtossUnit);

int getProtossUnitShield(struct protossUnit **CurrentProtossUnit);

int getProtossUnitType(struct protossUnit **CurrentProtossUnit);

#endif //STARCRAFT_PROTOSSUNITS_H