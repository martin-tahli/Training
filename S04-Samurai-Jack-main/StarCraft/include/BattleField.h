#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_


#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "BATTLE.h"
#include "WarUnitsH/BroodLord.h"
#include "WarUnitsH/Mutalisk.h"
#include "WarUnitsH/BattleCruser.h"
#include "WarUnitsH/Carrier.h"
#include "WarUnitsH/Viking.h"
#include "WarUnitsH/Phoenix.h"
#include "Vector.h"
#include "Defines.h"
#include "printWinnerTeamRace.h"


typedef struct {
    Vector Team1;
    Vector Team2;

} BattleField;


void generateTerranFleet(Vector *currentTeam, const char *terranFleetStr);
void generateZergFleet(Vector *currentTeam, const char *ZergFleetStr);
void generateProtossFleet(Vector* currentTeam, const char *protossFleetStr);
void fillTeam(int currentTeamRaceID, Vector* currentTeam, string currentTeamString);
void startBattle(BattleField *battleField);

void deinit(BattleField *battleField);


#endif /* BATTLEFIELD_H_ */
