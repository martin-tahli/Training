#include "CurrentAttackingUnitsH/CurrentAttackingPhoenix.h"

/**
 * This function processes the specifics of the Phoenix attack.
 * @param currentAttackUnit Pointer to the current Battle Phoenix.
 * @param currentTeam The Vector pointer to team of the Phoenix.
 * @param indx the index of the current unit.
 */
void currentAttackingPhoenix(struct Phoenix *currentAttackUnit, Vector* currentTeam, size_t indx){
    //setting damage

    struct basicUnit *currentTarget = vectorBack(currentTeam);

    int16_t damageFromPhoenix = phoenixAttack((struct Phoenix *) currentAttackUnit);

    (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, damageFromPhoenix);



    //currentTarget->health -= damageFromPhoenix;



    if (isUnitDead(currentTarget->health)) {   // ako ne go nameri trqbva hedyr vuv
        nextTarget(&currentTarget, &currentTeam);
        printKillMessage("Phoenix", indx, currentTeam->size);
    }

}