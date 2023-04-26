#include "CurrentAttackingUnitsH/CurrentAttackingMutalisk.h"

/**
 * This function processes the specifics of the Mutalisk attack.
 * @param currentAttackUnit Pointer to the current Mutalisk.
 * @param currentTeam The Vector pointer to team of the Mutalisk.
 * @param indx the index of the current unit
 */
void currentAttackingMutalisk(struct Mutalisk *currentAttackUnit, Vector* currentTeam, size_t indx){
    //setting damage

    struct basicUnit *currentTarget = vectorBack(currentTeam);

    int16_t damageFromMutalisk = mutaliskAttack((struct Mutalisk *) currentAttackUnit);

    (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, damageFromMutalisk);


    if (isUnitDead(currentTarget->health)) {   // ako ne go nameri trqbva hedyr vuv
        nextTarget(&currentTarget, &currentTeam);
        printKillMessage("Mutalisk", indx, currentTeam->size);
    }

}