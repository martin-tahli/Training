#include "ErrorHandler.h"
#include "printWinnerTeamRace.h"

void printCorrectWinner(int16_t winnerTeam) {
    int16_t winnerRace = 0;
    if (winnerTeam == 1) {
        winnerRace = team1RaceID;
    } else if (winnerTeam == 2) {
        winnerRace = team2RaceID;
    }

    switch (winnerRace) {

        case TERRAN:
            printf("Team: %d TERRAN WON!\n", winnerTeam);
            break;
        case PROTOSS:
            printf("Team: %d PROTOSS WON!\n", winnerTeam);
            break;
        case ZERG:
            printf("Team: %d  ZERG WON!\n", winnerTeam);
            break;
        default:
            printErrorStatus(ERR_IF_NOT_PROTOSS_TERRAN_ZERG);
            return;
    }

}
