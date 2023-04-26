#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>

#include "Pistol.h"
#include "Defines.h"
#include "VitalData.h"

typedef struct Player Player;

Player* PlayerInit(Pistol* currPistol, struct PlayerVitalData* currData, int playerID);

//====================== Getters =======================

struct PlayerVitalData* GetPlayerVitalData(struct Player* self);
Pistol* GetPlayerPistol(struct Player *self);
int GetPlayerID(struct Player *self);

//====================== Setters =======================

void SetPlayerVitalData(struct Player* self, struct PlayerVitalData* data);
void SetPlayerPistol(struct Player *self, Pistol *newPistol);
void SetPlayerID(struct Player *self, int newID);

#endif /* PLAYER_H_ */
