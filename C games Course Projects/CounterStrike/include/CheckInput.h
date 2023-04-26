
#ifndef S04_SAMURAI_JACK_CHECKINPUT_H
#define S04_SAMURAI_JACK_CHECKINPUT_H

#include "VitalData.h"
#include "Pistol.h"

/**
 * This function takes input for armor and health.
 * @param currentData the pair of health and armor.
 */
void takeInputVitalData(struct PlayerVitalData *currentData);

/**
 * This function takes pistol data.
 * @param currentPistol the pistol for which we are taking data.
 */
void takePistolData(Pistol *currentPistol);

#endif //S04_SAMURAI_JACK_CHECKINPUT_H
