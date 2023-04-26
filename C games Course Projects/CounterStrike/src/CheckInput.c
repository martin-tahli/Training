#include <stdbool.h>
#include <stdio.h>
#include "../include/CheckInput.h"
#include "VitalData.h"
#include "Pistol.h"




void takeInputVitalData(struct PlayerVitalData *currentData) {

    char input[1000];
    int newHP = 0;
    int newArmor = 0;

    printf("\n\nPlease, enter data for health and armor: \n(Example)-Enter health and armor here: 120 0\n -Enter data here: \n");

    do {
        fflush(stdin);
        fgets(input, sizeof(input) ,stdin);
        fflush(stdin);
        if (sscanf(input, "%d %d", &newHP, &newArmor) == 2) {
            fflush(stdin);
            break;
        }
        fflush(stdin);
        printf("Invalid input, please try again.\n");
    } while(true);


    setHealth(currentData, newHP);
    setArmor(currentData, newArmor);
}

void takePistolData(struct Pistol *currentPistol) {

    char input[1000];
    int type = 0;
    int damage = 0;
    int clipSize = 0;
    int totalAmmo = 0;

    printf("\n\nPlease, enter data for pistol here: Type, damage, clip size and total ammo: \n(Example)-Enter data here: 0 8 9 71\n -Enter data here: ");

    do {
        fflush(stdin);
        fgets(input, sizeof(input) ,stdin);
        fflush(stdin);
        if (sscanf(input, "%d %d %d %d", &type, &damage, &clipSize, &totalAmmo) == 4) {
            fflush(stdin);
            break;
        }
        fflush(stdin);
        printf("Invalid input, please try again.\n");
    } while(true);

    SetPistolType(currentPistol, type);
    SetPistolDamagePerRound(currentPistol, damage);
    SetPistolClipSize(currentPistol, clipSize);
    SetPistolCurrentClipAmmo(currentPistol, clipSize);
    SetPistolRemainingTotalAmmo(currentPistol, totalAmmo);
}
