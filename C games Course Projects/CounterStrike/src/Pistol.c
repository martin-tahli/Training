
#include <stdlib.h>

#include "Pistol.h"


struct Pistol {
    int pistolType;
    int damagePerRound;
    int clipSize;
    int currClipBullets;
    int remainingAmmo;
};


struct Pistol *initPistol(void) {

    struct Pistol *newPistol = (struct Pistol*)malloc(sizeof(struct Pistol));
    if (newPistol == NULL) {
        return 0; //Error Handle
    }
    newPistol->pistolType = 0;
    newPistol->damagePerRound = 0;
    newPistol->clipSize = 0;
    newPistol->currClipBullets = 0;
    newPistol->remainingAmmo = 0;
    return newPistol;

}

//==================== Getters ==============================

int GetPistolType(Pistol *self) {
    return self->pistolType;
}

int GetPistolDamagePerRound(Pistol *self) {
    return self->damagePerRound;
}

int GetPistolClipSize(Pistol *self) {
    return self->clipSize;
}

int GetPistolCurrentClipAmmo(Pistol *self) {
    return self->currClipBullets;
}

int GetPistolRemainingTotalAmmo(Pistol *self) {
    return self->remainingAmmo;
}
//==================== Setters ==============================

void SetPistolType(Pistol *self, int newPistolTypeID) {
    self->pistolType = newPistolTypeID;
}

void SetPistolDamagePerRound(Pistol *self, int newDamage) {
    self->damagePerRound = newDamage;
}

void SetPistolClipSize(Pistol *self, int newClipSize) {
    self->clipSize = newClipSize;
}

void SetPistolCurrentClipAmmo(Pistol *self, int newClipAmmo) {
    self->currClipBullets = newClipAmmo;
}

void SetPistolRemainingTotalAmmo(Pistol *self, int newRemainingAmmo) {
    self->remainingAmmo = newRemainingAmmo;
}