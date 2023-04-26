#include "CurrentAttackingUnitsH/CurrentAttackingCarrier.h"

/**
 * This function processes the specifics of the Carrier attack.
 * @param currentAttackUnit Pointer to the current Carrier.
 * @param currentTeam The Vector pointer to team of the Carrier.
 * @param indx the index of the current unit
 */
void currentAttackingCarrier(struct Carrier *currentAttackUnit, Vector *currentTeam, size_t indx) {

    struct basicUnit *currentTarget = vectorBack(currentTeam);

    int16_t countInterceptors = getCountInterceptors((struct Carrier *) currentAttackUnit);

    int16_t dmgFromCarrier = getDmgInterceptor((struct Carrier *) currentAttackUnit);

    while (countInterceptors > 0) {
        if (currentTarget->health <= 0)
        {
//            (**fPtrUnitArray[currentTarget->unitType])(currentTarget, dmgFromCarrier);
//            countInterceptors--;
            currentTarget->health = 0;
            if(nextTarget(&currentTarget, &currentTeam) ==  FALSE) {
                printKillMessage("Carrier", indx, currentTeam->size);
                break;
            }
            printKillMessage("Carrier", indx, currentTeam->size);
            (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, dmgFromCarrier);
            countInterceptors--;
            continue;
        }
//        currentTarget->health = 0;
//        nextTarget(&currentTarget, &currentTeam);
//        printKillMessage("Carrier", indx, currentTeam->size);
//        (**fPtrUnitArray[currentTarget->unitType])(currentTarget, dmgFromCarrier);
//
//        countInterceptors--;
        (**fPtrDmgReceiveUnitArray[currentTarget->unitType])(currentTarget, dmgFromCarrier);
        countInterceptors--;
    }
}
