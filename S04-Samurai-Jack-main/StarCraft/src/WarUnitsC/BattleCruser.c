#include "WarUnitsH/BattleCruser.h"


/**
 * Creates a BattleCruser Unit with a predefined amount of members.
 * @return A pointer to a BattleCruser stored in the memory.
 */
struct BattleCruser *newBattleCruserUnit(void) {

    struct BattleCruser *self = (struct BattleCruser *) malloc(sizeof(struct BattleCruser));
    if (self == NULL) {
        printErrorStatus(ERR_ALLOCATE_BATTLE_CRUISER);
        return FALSE;
    }
    self->terranUnit.BasicUnit.health = BATTLE_CRUSER_HEALTH;
    self->terranUnit.BasicUnit.damage = BATTLE_CRUSER_DAMAGE;
    self->terranUnit.BasicUnit.unitType = BATTLE_CRUSER;
    self->terranUnit.BasicUnit.raceType = TERRAN;
    self->terranUnit.trackAttacks = 0;

    return self;
}

/**
 * Check if enemy type unit is Phoenix.
 * @param CurrentViking pointer pointing current instance of type Viking.
 * @param enemyUnitType number that identifies enemy unit.
 * @return Returns multiply 5 times damage dealt every 5th shot. Else return normal Damage.
 */
int16_t battleCruserAttack(struct BattleCruser *self) {
    self->terranUnit.trackAttacks++;
    if (self->terranUnit.trackAttacks % YAMATO_CANNON_LOADING_TURNS == 0)
        return self->terranUnit.BasicUnit.damage * 5; //We multiply damage dealt every 5th shot.
    return self->terranUnit.BasicUnit.damage;
}

/**
 * This function calculates the amount of damage the Battle Cruiser will be receiving.
 * @param self pointer of type Battle Cruiser to the current unit.
 * @param damageReceived the amount of damage
 */
void damageReceivedBattleCruser(struct BattleCruser *self, int16_t damageReceived) {
    self->terranUnit.BasicUnit.health -= damageReceived;
}