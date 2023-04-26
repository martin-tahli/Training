#ifndef STARCRAFT_BASICUNITTYPE_H
#define STARCRAFT_BASICUNITTYPE_H
#include <stdint.h>


struct basicUnit {
    int16_t health;
    int16_t damage;
    int16_t unitType;
    int16_t raceType;
};
#endif //STARCRAFT_BASICUNITTYPE_H

