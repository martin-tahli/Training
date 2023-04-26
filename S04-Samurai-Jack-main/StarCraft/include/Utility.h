#ifndef STARCRAFT_UTILITY_H
#define STARCRAFT_UTILITY_H

#include <stdint.h>
#include <stdio.h>
#include "Vector.h"
#include "UnitTypesStructuresH/BasicUnitType.h"
#include "Defines.h"
#include "UnitTypesStructuresH/ProtossUnitType.h"
#include "UnitTypesStructuresH/TerranUnitType.h"




int nextTarget(struct basicUnit **currentTarget, Vector **currentTeam);

int isUnitDead(int16_t enemyHP);

void printKillMessage(char *name, size_t indx, size_t indxOfTarget);

void printRoundEnd(Vector *currentTeam);


#endif //STARCRAFT_UTILITY_H
