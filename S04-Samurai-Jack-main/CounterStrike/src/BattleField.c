#include <stdio.h>
#include <stdlib.h>
#include "BattleField.h"
#include "CheckInput.h"
#include "Player.h"
#include "Pistol.h"
#include "VitalData.h"
#include "PistolUtilities.h"


// asking for player health and armor, each for loop iteration is a player

void createPlayers(BattleField *bf) {


    struct PlayerVitalData *dataCollection[PLAYERS_COUNT] = {};
    struct Pistol *pistolsData[PLAYERS_COUNT] = {};

    for (int i = 0; i < PLAYERS_COUNT; i++) {
        //initing and taking vital data, then setting it in the func
        dataCollection[i] = initVitalData();
        takeInputVitalData(dataCollection[i]);
    }

    for (int i = 0; i < PLAYERS_COUNT; i++) {
        //initing and taking pistol data, then setting it in the func
        pistolsData[i] = initPistol();
        takePistolData(pistolsData[i]);
    }

    for (int i = 0; i < PLAYERS_COUNT; i++) {
        // setting the proper pistol to the player

        struct Pistol *currentPistol = pistolsData[i];
        struct PlayerVitalData *currentData = dataCollection[i];
        bf->players[i] = PlayerInit(currentPistol, currentData, i);
    }
}

void startBattle(BattleField *bf) {

    Player *currentAttacker;
    Player *currentTarget;
    Pistol *currentPistol;
    struct PlayerVitalData *currentTargetData;
    struct PlayerVitalData *currentAttackerData;
    int currentAttackerStatus;
    int currentAttackerID;
    int counter = 0;

    while(true) {

        if (counter % 2 == 0) {
            currentAttacker = bf->players[0];
            currentTarget = bf->players[1];
        }
        else {
            currentAttacker = bf->players[1];
            currentTarget = bf->players[0];
        }
        //attacker data
        currentPistol = GetPlayerPistol(currentAttacker);
        currentAttackerID = GetPlayerID(currentAttacker);
        currentAttackerData = GetPlayerVitalData(currentAttacker);
        currentAttackerStatus = getStatus(currentAttackerData);
        //target data
        currentTargetData = GetPlayerVitalData(currentTarget);

        printf("\nPlayerID %d turn:\n", currentAttackerID);

        if(CheckNoAmmo(currentPistol)) {
            setStatus(currentAttackerData, PASSIVE);
        }

        if (currentAttackerStatus == ACTIVE) {
            if(ProcessTurn(currentTargetData, currentPistol)) {
                // this means somebody died.
                break;
            }
        }
        else {
            printf("No ammo left\n");
        }
        counter++;
    }

    printf("\nPlayer with ID: %d wins!\n", currentAttackerID);
}

void printIntroMsg(){
    printf("\n\n\n\t\tWellcome to the simulation version of the famous game Counter Strike.\n\t\tYou need to enter data for the players."
           "\n\t\tOnes for the first player and then for the second one.\n\n\t\t\t\t\tLet's start and enjoy the game!\n");
    printf("\t\t=======================================================\n");
    printf("\t\t---------------->>> COUNTER STRIKE <<<-----------------\n");
    printf("\t\t=======================================================\n");
}

void deinit(BattleField *battleField) {

    Player* currentPlayer;
    struct PlayerVitalData* currentData;
    Pistol* currentPistol;

    for (int i = 0; i < PLAYERS_COUNT; i++) {

        currentPlayer = battleField->players[i];
        currentData = GetPlayerVitalData(currentPlayer);
        currentPistol = GetPlayerPistol(currentPlayer);

        //free pistol
        free(currentPistol);
        SetPlayerPistol(currentPlayer, NULL);

        //free vital data
        free(currentData);
        SetPlayerVitalData(currentPlayer, NULL);

        //free player
        free(currentPlayer);
        battleField->players[i] = NULL;
    }
}