#include "BattleField.h"
#include "CheckInput.h"
#include "RaceUtilities.h"

int team1RaceID;
int team2RaceID;

int main(){


    const int buffSize = 50;
    char team1[buffSize];
    char team2[buffSize];

    askForRace();


    printCurrentRaceUnits(team1RaceID);
    takeRaceInput(team1, team1RaceID);
    printCurrentRaceUnits(team2RaceID);
    takeRaceInput(team2, team2RaceID);

    BattleField battleField;

    fillTeam(team1RaceID, &battleField.Team1, team1);
    fillTeam(team2RaceID, &battleField.Team2, team2);

    startBattle(&battleField);


    deinit(&battleField);

}

