#include "BATTLE.h"

/**
 * This function processes the battle by taking team 1 first and team 2 second.
 * @param Team1 Vector pointer to the first team.
 * @param Team2 Vector pointer to the second team.
 * @return returns the winning team, which is either 1 or 2
 */
int BATTLE(Vector * Team1, Vector * Team2) {

    while (1) {
        size_t team1ArmySize = vectorGetSize(Team1);    // the current size of the protoss army
        //===================TEAM 1 TURN========================
        for (size_t i = 0; i < team1ArmySize; i++) {
            // check to see if team1 army exists
            if (vectorGetSize(Team2) <= 0) {

                return TEAM1;
            }
            struct basicUnit *currentAttackUnit = vectorGet(Team1,i); // pointer to current unit at index i
            (**fPtrAttackingUnitsArray[currentAttackUnit->unitType])(currentAttackUnit, Team2, i);

        }

        // check to see if terran army exists
        if (vectorGetSize(Team2) <= 0) {
            return TEAM1;
        }
        printRoundEnd(Team2);

        //===================TEAM 2 TURN========================
        size_t team2ArmySize = vectorGetSize(Team2);  // the current size of the protoss army
        for (size_t i = 0; i < team2ArmySize; i++) {
            // check to see if team1 army exists
            if (vectorGetSize(Team1) <= 0) {
                return TEAM2;

            }
            struct basicUnit *currentAttackUnit = vectorGet(Team2,i); // pointer to current unit at index i

            (**fPtrAttackingUnitsArray[currentAttackUnit->unitType])(currentAttackUnit, Team1, i);
        }
        // check to see if team1 army exists
        if (vectorGetSize(Team1) <= 0) {
            return TEAM2;
        }
        printRoundEnd(Team1);
    }

}