
#include <stdlib.h>

#include "Pistol.h"
#include "Player.h"



struct Player{
    struct PlayerVitalData* data;
    Pistol* pistol;
    int playerId;
};

Player* PlayerInit(struct Pistol* currPistol, struct PlayerVitalData* currData, int playerID) {

    Player *self = malloc(sizeof(Player));
    if (self == NULL) {
        return 0; //Error Handle
    }

    self->data = currData;
    self->pistol = currPistol;
    self->playerId = playerID;
    return self;
}

//================================ Getters =======================================

struct PlayerVitalData* GetPlayerVitalData(struct Player* self) {
    return self->data;
}

Pistol* GetPlayerPistol(struct Player *self) {
    return self->pistol;
}

int GetPlayerID(struct Player *self) {
    return self->playerId;
}

//================================ Setters =======================================

void SetPlayerVitalData(struct Player* self, struct PlayerVitalData* data) {
    self->data = data;
}

void SetPlayerPistol(struct Player *self, struct Pistol *newPistol) {
    self->pistol = newPistol;
}

void SetPlayerID(struct Player *self, int newID) {
    self->playerId = newID;
}
