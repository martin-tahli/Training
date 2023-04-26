#include "Utility.h"

/**
 * This function picks the next target.
 * @param currentTarget double basicUnit pointer to current target.
 * @param currentTeam double Vector pointer to the current team.
 * @return true if there is a next target and false if there isn't.
 */
int nextTarget(struct basicUnit **currentTarget, Vector **currentTeam) {

    vectorPop(*currentTeam);
    if (vectorGetSize(*currentTeam) != 0) {
        *currentTarget = vectorBack(*currentTeam);  //size -1

        //**curIndexOfItem = vectorGetSize(*currentTeam) ;
        return TRUE;
    }
    return FALSE;
}

/**
 * This function checks if a unit is dead by checking its health.
 * @param enemyHP Health of the current unit.
 * @return true if dead and false if not.
 */
int isUnitDead(int16_t enemyHP) {

    if (enemyHP <= 0) {
        return TRUE;
    }
    return FALSE;
}

/**
 *
 * @param name
 * @param indx
 * @param indxOfTarget
 */
void printKillMessage(char *name, size_t indx, size_t indxOfTarget) {

    printf("%s with ID: %ld killed enemy airship with ID: %zu\n", name, indx, indxOfTarget); // Use %ld for Linux. and %lld for Windows.
}

/**
 * This function prints the round end message at the end of every round.
 * @param currentTeam vector pointer to the current team.
 */
void printRoundEnd(Vector *currentTeam) {

    struct basicUnit *currentTarget = (struct basicUnit *) vectorBack(currentTeam);

    if (currentTarget->raceType == TERRAN) {
        printf("Last Terran AirShip with ID: %zu has %d health left\n", currentTeam->size - 1,
               (*currentTarget).health);

    } else if (currentTarget->raceType == PROTOSS) {
        struct protossUnit *currentProtoss = (struct protossUnit *) currentTarget;
        printf("Last Protoss AirShip with ID: %zu has %d health and %d shield left\n", currentTeam->size - 1,
               (*currentTarget).health, currentProtoss->shield);

    } else if (currentTarget->raceType == ZERG) {

        printf("Last Zerg AirShip with ID: %zu has %d health left\n", currentTeam->size - 1,
               (*currentTarget).health);


    }
}

