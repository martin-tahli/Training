
#ifndef S04_SAMURAI_JACK_GLOCK_H
#define S04_SAMURAI_JACK_GLOCK_H

#include <stdbool.h>
#include "VitalData.h"
#include "Pistol.h"

/**
 * This function processes the current turn
 * @param currentTargetData - The data of the player that is getting shots.
 * @param currentShootingPistol - The pistol of the attacker.
 * @return true if enemy killed, false if enemy alive
 */
bool ProcessTurn(struct PlayerVitalData *currentTargetData, Pistol* currentShootingPistol);

/**
 * This function reloads a given pistol.
 * @param currentPistol - Shooting pistol.
 * @return true if reload successful, false if no ammo
 */
bool Reload(Pistol* currentPistol);

/**
 * This function checks the ammunition of the attacker.
 * @param pistolToCheck The pistol of the attacker.
 * @return true if there is ammo, false if no ammo.
 */
bool CheckNoAmmo(Pistol* pistolToCheck);

/**
 * This function fires the Glock Pistol.
 * @param currentTargetData  The data of the target.
 * @param currentGlock The current shooting Glock.
 * @return true if enemy is killed, false if not.
 */
bool GlockFire(struct PlayerVitalData *currentTargetData, Pistol* currentGlock);

/**
 * This function fires the Deser Eagle Pistol.
 * @param currentTargetData The data of the target.
 * @param currentDesertEagle The current shooting Desert Eagle.
 * @return true if enemy is killed, false if not.
 */
bool DesertEagleFire(struct PlayerVitalData *currentTargetData, Pistol* currentDesertEagle);

/**
 * This function processes the damage.
 * @param defenderData The data of the target.
 * @param shootingPistol The shooting Pistol.
 * @return true if enemy is killed, false if not.
 */
bool DealDamage(struct PlayerVitalData *defenderData, Pistol* shootingPistol);

/**
 * This function checks whether a unit with given hp is dead or not.
 * @param currentHP The HP of the unit.
 * @return true if dead, false if not.
 */
bool checkDead(int currentHP);

#endif //S04_SAMURAI_JACK_GLOCK_H
