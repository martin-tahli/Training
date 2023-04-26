#include "CurrentAttackingUnitsH/CurrentAttackingViking.h"

/**
 * This function processes the specifics of the Viking attack.
 * @param currentAttackUnit Pointer to the current Viking.
 * @param currentTeam The Vector pointer to team of the Viking.
 * @param indx the index of the current unit.
 */
void currentAttackingViking(struct Viking *currentAttackUnit, Vector *currentTeam,size_t indx) {

    struct basicUnit *currentTarget = vectorBack(currentTeam);
    int16_t damageFromViking = vikingAttack((struct Viking *) currentAttackUnit, (currentTarget)->unitType);

    (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, damageFromViking);



    if (isUnitDead((currentTarget)->health)) {
        nextTarget(&currentTarget, &currentTeam);
        printKillMessage("Viking", indx, currentTeam->size);
    }
}