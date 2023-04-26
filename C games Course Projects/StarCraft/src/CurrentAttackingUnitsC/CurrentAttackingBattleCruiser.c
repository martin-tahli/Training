#include "CurrentAttackingUnitsH/CurrentAttackingBattleCruiser.h"

/**
 * This function processes the specifics of the Battle Cruiser attack.
 * @param currentAttackUnit Pointer to the current Battle Cruiser
 * @param currentTeam The Vector pointer to team of the Battle Cruiser
 * @param indx the index of the current unit
 */
void currentAttackingBC(struct BattleCruser *currentAttackUnit, Vector *currentTeam, size_t indx) {

    struct basicUnit *currentTarget = vectorBack(currentTeam);
    //setting damage
    int16_t damageFromBC = battleCruserAttack((struct BattleCruser *) currentAttackUnit);

    (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, damageFromBC);

    if (isUnitDead(currentTarget->health)) {
        nextTarget(&currentTarget, &currentTeam);
        printKillMessage("BattleCruser", indx, currentTeam->size);
    }
}