#ifndef STARCRAFT_TERRANUNITS_H
#define STARCRAFT_TERRANUNITS_H
#include <stdint.h>
#include "UnitTypesStructuresH/BasicUnitType.h"

struct terranUnit {
    struct basicUnit BasicUnit;
    int16_t trackAttacks;
};


#endif //STARCRAFT_TERRANUNITS_H


