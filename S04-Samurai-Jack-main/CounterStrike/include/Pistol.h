#ifndef PISTOL_H_
#define PISTOL_H_

#include "Defines.h"

typedef struct Pistol Pistol;


struct Pistol *initPistol(void);

//======================== Getters ======================

int GetPistolType(Pistol* self);
int GetPistolDamagePerRound(Pistol* self);
int GetPistolClipSize(Pistol* self);
int GetPistolCurrentClipAmmo(Pistol* self);
int GetPistolRemainingTotalAmmo(Pistol* self);

//======================== Setters ======================

void SetPistolType(Pistol* self, int newPistolTypeID);
void SetPistolDamagePerRound(Pistol* self, int newDamage);
void SetPistolClipSize(Pistol* self, int newClipSize);
void SetPistolCurrentClipAmmo(Pistol* self, int newClipAmmo);
void SetPistolRemainingTotalAmmo(Pistol* self, int newRemainingAmmo);

#endif /* PISTOL_H_ */
