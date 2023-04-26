


#include <stdlib.h>

#include "Defines.h"
#include "../include/VitalData.h"


struct PlayerVitalData{
    int health;
    int armor;
    int status;
};

struct PlayerVitalData *initVitalData(void) {

    struct PlayerVitalData *newVitalData = (struct PlayerVitalData*)malloc(sizeof(struct PlayerVitalData));
    if (newVitalData == NULL) {
        return 0; //Error Handle
    }
    newVitalData->health = 0;
    newVitalData->armor = 0;
    newVitalData->status = ACTIVE;

    return newVitalData;
}


void setHealth(struct PlayerVitalData* const self, const int health){
    self->health = health;
}

void setArmor(struct PlayerVitalData* const self, const int armor){
    self->armor = armor;
}

void setStatus(struct PlayerVitalData* const self, int newStatus) {
    self->status = newStatus;
}


int getStatus(const struct PlayerVitalData* const self) {
    return self->status;
}

int getHealth(const struct PlayerVitalData* const self){
    return self->health;
}

int getArmor(const struct PlayerVitalData* const self){
    return self->armor;
}