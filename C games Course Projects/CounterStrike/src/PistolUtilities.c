
#include <stdio.h>

#include "../include/PistolUtilities.h"
#include "VitalData.h"
#include "Defines.h"


bool ProcessTurn(struct PlayerVitalData *currentTargetData, Pistol* currentShootingPistol) {

    int currentPistolType = GetPistolType(currentShootingPistol);

    if (currentPistolType == GLOCK) {
        if(GlockFire(currentTargetData, currentShootingPistol)) {
            return true;
        }
    }
    else if (currentPistolType == DESERT_EAGLE) {
        if(DesertEagleFire(currentTargetData, currentShootingPistol)) {
            return true;
        }
    }

    return false;
}

bool CheckNoAmmo(Pistol* pistolToCheck) {
    int currentClipAmmo = GetPistolCurrentClipAmmo(pistolToCheck);
    int remainingAmmo = GetPistolRemainingTotalAmmo(pistolToCheck);

    if (currentClipAmmo == 0 && remainingAmmo == 0) {
        return true;
    }
    return false;
}

bool Reload(Pistol* currentPistol) {

    int currentPistolClipSize = GetPistolClipSize(currentPistol);
    int currentPistolRemainingAmmo = GetPistolRemainingTotalAmmo(currentPistol);
    int difference;

    if (currentPistolRemainingAmmo == 0) {
        printf("No ammo left\n");
        return false;
    }

    if (currentPistolClipSize <= currentPistolRemainingAmmo) {
        // ammo logic
        currentPistolRemainingAmmo -= currentPistolClipSize;
        SetPistolRemainingTotalAmmo(currentPistol, currentPistolRemainingAmmo);
        // filling the clip
        SetPistolCurrentClipAmmo(currentPistol, currentPistolClipSize);
        printf("Reloading...\ncurrClipBullets: %d, remainingAmmo: %d\n",
               GetPistolCurrentClipAmmo(currentPistol), GetPistolRemainingTotalAmmo(currentPistol));
    }
    else {
        difference = currentPistolClipSize - currentPistolRemainingAmmo;
        SetPistolCurrentClipAmmo(currentPistol, currentPistolClipSize - difference);
        SetPistolRemainingTotalAmmo(currentPistol, 0);
        printf("Reloading...\ncurrClipBullets: %d, remainingAmmo: %d\n",
               GetPistolCurrentClipAmmo(currentPistol), GetPistolRemainingTotalAmmo(currentPistol));
    }
    return true;
}

bool GlockFire(struct PlayerVitalData *currentTargetData, Pistol* currentGlock) {

    int glockCurrentClipAmmo = GetPistolCurrentClipAmmo(currentGlock);
    int numberOfShots = ROUNDS_PER_FIRE;

    if(glockCurrentClipAmmo >= numberOfShots) {
        // ammo logic
        glockCurrentClipAmmo -= numberOfShots;
        SetPistolCurrentClipAmmo(currentGlock,glockCurrentClipAmmo);
        // deal damage

        for (int i = 0; i < numberOfShots; i++) {
            //deal damage
            if (DealDamage(currentTargetData, currentGlock)) {
                return true;
            }
        }
    }
    else {
        for (int i = 0; i < glockCurrentClipAmmo; i++) {
            //deal damage
            if (DealDamage(currentTargetData, currentGlock)) {
                return true;
            }
        }
        glockCurrentClipAmmo = 0;
        SetPistolCurrentClipAmmo(currentGlock, glockCurrentClipAmmo);

        Reload(currentGlock);
    }

    return false;
}

bool DesertEagleFire(struct PlayerVitalData *currentTargetData, Pistol* currentDesertEagle) {

    int desertEagleCurrentClipAmmo = GetPistolCurrentClipAmmo(currentDesertEagle);

    if (desertEagleCurrentClipAmmo > 0) {
        if (DealDamage(currentTargetData, currentDesertEagle)) {
            return true;
        }
        desertEagleCurrentClipAmmo -= 1;
        SetPistolCurrentClipAmmo(currentDesertEagle, desertEagleCurrentClipAmmo);
    }
    else {
        Reload(currentDesertEagle);
    }
    return false;
}

bool DealDamage(struct PlayerVitalData *defenderData, Pistol* shootingPistol) {

    int currentHP = getHealth(defenderData);
    int currentArmor = getArmor(defenderData);
    int pistolHealthDamage = 0;
    int pistolArmorDamage = 0;
    int damageCarryOver;

    int pistolType = GetPistolType(shootingPistol);
    int pistolDamage = GetPistolDamagePerRound(shootingPistol);


    if(currentArmor > 0) {

        switch (pistolType) {
            case GLOCK:
                pistolHealthDamage = pistolDamage / 2;
                pistolArmorDamage = pistolDamage / 2;
                break;
            case DESERT_EAGLE:
                pistolHealthDamage = (int) (pistolDamage * 0.75);
                pistolArmorDamage = (int) (pistolDamage * 0.25);
                break;
            default:
                printf("\nError trying to get pistolType.\n");
                break;  // fix error handling
        }

        // check to see if there will be damage carry over

        if ((currentArmor - pistolArmorDamage) <= 0) {
            damageCarryOver = pistolArmorDamage - currentArmor;
            currentArmor = 0;
            setArmor(defenderData, currentArmor);

            currentHP -= pistolHealthDamage + damageCarryOver;
            if (checkDead(currentHP)){
                printf("Enemy left with: %d health and %d armor\n", currentHP, currentArmor);
                return true;
            }
            setHealth(defenderData, currentHP);
            printf("Enemy left with: %d health and %d armor\n", currentHP, currentArmor);
        }
        else {
            currentHP -= pistolHealthDamage;
            currentArmor -= pistolArmorDamage;

            if (checkDead(currentHP)){
                printf("Enemy left with: %d health and %d armor\n", currentHP, currentArmor);
                return true;
            }
            setHealth(defenderData, currentHP);
            setArmor(defenderData, currentArmor);
            printf("Enemy left with: %d health and %d armor\n", currentHP, currentArmor);
        }

    }
    else {
        currentHP -= pistolDamage;
        if (checkDead(currentHP)){
            printf("Enemy left with: %d health and %d armor\n", currentHP, currentArmor);
            return true;
        }
        setHealth(defenderData, currentHP);
        printf("Enemy left with: %d health and %d armor\n", currentHP, currentArmor);
    }
    return false;
}

bool checkDead(int currentHP) {
    if (currentHP <= 0) {
        return true;
    }
    return false;
}
