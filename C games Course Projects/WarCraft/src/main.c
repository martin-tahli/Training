#include <stdio.h>
#include <stdlib.h>
#include "BattleField.h"
#include "CheckInput.h"
#include "BattleProcessor.h"

int main() {

int team1Size;
int team2Size;


    PrintHelloMessage();

   // setting the battlefield environment
    BattleField battleField;

    printf("------------------>> Team 1 <<------------------\n");
    team1Size = AskForTeamSize();

    printf("------------------>> Team 2 <<------------------\n");
    team2Size = AskForTeamSize();

    printf("Select units for the first team\n");
    fillTeam(&battleField.Team1, team1Size);

    printf("Select units for the second team\n");
    fillTeam(&battleField.Team2, team2Size);

    Battle(&battleField.Team1, &battleField.Team2);


    // deiniting the BF
    deinit(&battleField);

    return EXIT_SUCCESS;
}
