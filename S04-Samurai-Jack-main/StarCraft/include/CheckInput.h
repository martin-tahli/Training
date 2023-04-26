#ifndef STARCRAFT_CHECKINPUTVALUE_H
#define STARCRAFT_CHECKINPUTVALUE_H

#include "Defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void takeRaceInput(char currentRaceArray[], int currentRaceID);
void terminateTrailingNewline(string input);
int raceUnitInputCheck(char raceArray[], int currentRaceID);
int validateIntegerInput();

#endif //STARCRAFT_CHECKINPUTVALUE_H


