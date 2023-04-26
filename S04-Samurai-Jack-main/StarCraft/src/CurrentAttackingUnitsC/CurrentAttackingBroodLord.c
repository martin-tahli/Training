#include "CurrentAttackingUnitsH/CurrentAttackingBroodLord.h"

/**
 * This function processes the specifics of the Battle Cruiser attack.
 * @param currentAttackUnit Pointer to the current Brood Lord.
 * @param currentTeam The Vector pointer to team of the Brood Lord.
 * @param indx the index of the current unit.
 */
void currentAttackingBroodLord(struct BroodLord *currentAttackUnit, Vector *currentTeam, size_t indx) {

    struct basicUnit *currentTarget = vectorBack(currentTeam);

    int16_t damageFromBroodLord= broodLordAttack((struct BroodLord *) currentAttackUnit);

    (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, damageFromBroodLord);



    if (isUnitDead((currentTarget)->health)) {
        nextTarget(&currentTarget, &currentTeam);
        printKillMessage("Brood Lord", indx, currentTeam->size);
    }
}