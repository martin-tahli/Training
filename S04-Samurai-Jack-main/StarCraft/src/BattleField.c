#include "BattleField.h"

/**
 * This function fills the given team vector according to its race ID.
 * @param currentTeamRaceID the race ID of the team.
 * @param currentTeam the empty vector.
 * @param currentTeamString the user input.
 */
void fillTeam(int currentTeamRaceID, Vector *currentTeam, string currentTeamString) {
    switch (currentTeamRaceID) {
        case TERRAN:
            generateTerranFleet(currentTeam, currentTeamString);
            break;
        case PROTOSS:
            generateProtossFleet(currentTeam, currentTeamString);
            break;
        case ZERG:
            generateZergFleet(currentTeam, currentTeamString);
            break;
        default:
            break;  // error handle
    }
}


/**
 *  This function generates the terran fleet.
 * @param battleField this is a pointer to the battlefield
 * @param terranFleetStr this is a pointer to the user input.
 */
void generateTerranFleet(Vector *currentTeam, const char *terranFleetStr) {

    Vector *ptrTerranFleet = currentTeam;   // pointer to the vector of the terran fleet.
    vectorInit(ptrTerranFleet, strlen(terranFleetStr));  // TO DO--- initialising the vector.

    size_t sizeTerranFleet = strlen(terranFleetStr);
    // loop to iterate through input and fill the vector with the appropriate units.
    for (size_t i = 0; i < sizeTerranFleet; i++) {

        if (terranFleetStr[i] == 'v') {
            vectorSet(ptrTerranFleet, i, newVikingUnit());  // create a new viking object at current index
        } else if (terranFleetStr[i] == 'b') {
            vectorSet(ptrTerranFleet, i, newBattleCruserUnit()); // create a new bt cruiser object at current index
        }
    }

}

/**
 * This function generates the protoss fleet.
 * @param battleField this is a pointer to the battlefield
 * @param protossFleetStr this is a pointer to the user input
 */
void generateProtossFleet(Vector *currentTeam, const char *protossFleetStr) {

    vectorInit(currentTeam, strlen(protossFleetStr));  // initialising the vector.

    size_t sizeProtossFleet = strlen(protossFleetStr);
    // loop to iterate through input and fill the vector with the appropriate units.
    for (size_t i = 0; i < sizeProtossFleet; i++) {
        if (protossFleetStr[i] == 'p') {
            vectorSet(currentTeam, i, newPhoenixUnit());  // create a new phoenix object at current index
        } else if (protossFleetStr[i] == 'c') {
            vectorSet(currentTeam, i, newCarrierUnit()); // create a new carrier object at current index
        }
    }
}

/**
 * This function generates the Zerg fleet.
 * @param currentTeam empty vector to the team that will be the fleet.
 * @param ZergFleetStr the input string containing the army composition.
 */
void generateZergFleet(Vector *currentTeam, const char *ZergFleetStr) {

    vectorInit(currentTeam, strlen(ZergFleetStr));  // initialising the vector.

    size_t sizeZergFleet = strlen(ZergFleetStr);
    // loop to iterate through input and fill the vector with the appropriate units.
    for (size_t i = 0; i < sizeZergFleet; i++) {
        if (ZergFleetStr[i] == 'm') {
            vectorSet(currentTeam, i, newMutalisk());  // create a new Mutalisk object at current index
        } else if (ZergFleetStr[i] == 'b') {
            vectorSet(currentTeam, i, newBroodLord()); // create a new BroodLord object at current index
        }
    }
}

/**
 * This function starts the battle.
 * @param battleField pointer to the battlefield.
 */
void startBattle(BattleField *battleField) {

    while (1) {
        int16_t winnerTeam = BATTLE(&battleField->Team1, &battleField->Team2);
        printCorrectWinner(winnerTeam);
        break;
    }
}



/**\n
 * This function deinit the battlefield vectors and their respective units.
 * @param battleField the battle field to be freed.
 */
void deinit(BattleField *battleField) {

    for (size_t i = 0; i < battleField->Team1.capacity; i++) {

        battleField->Team1.size = battleField->Team1.capacity;

        struct basicUnit *temp = vectorGet(&battleField->Team1, i);

        free(temp);

    }

    vectorFree(&battleField->Team1);

    for (size_t i = 0; i < battleField->Team2.capacity; i++) {

        battleField->Team2.size = battleField->Team2.capacity;

        struct basicUnit *temp = vectorGet(&battleField->Team2, i);

        free(temp);
    }

    vectorFree(&battleField->Team2);
}


