#ifndef S04_SAMURAI_JACK_VITALDATA_H
#define S04_SAMURAI_JACK_VITALDATA_H


struct PlayerVitalData *initVitalData(void);

//======================== Setters ======================
void setHealth(struct PlayerVitalData* self, int health);
void setArmor(struct PlayerVitalData* self, int armor);
void setStatus(struct PlayerVitalData* self, int newStatus);

//======================== Getters ======================
int getHealth(const struct PlayerVitalData*  self);
int getArmor(const struct PlayerVitalData* self);
int getStatus(const struct PlayerVitalData* self);
#endif //S04_SAMURAI_JACK_VITALDATA_H
