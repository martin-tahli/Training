#ifndef STARCRAFT_CURRENTATTACKINGBATTLECRUISER_H
#define STARCRAFT_CURRENTATTACKINGBATTLECRUISER_H


#include "WarUnitsH/BattleCruser.h"
#include "Utility.h"
#include "FuncPointersForDefenceInvokeH/FunctionsPtrDamageReceiveUnits.h"


void currentAttackingBC(struct BattleCruser *currentAttackUnit, Vector *currentTeam, size_t indx);

#endif //STARCRAFT_CURRENTATTACKINGBATTLECRUISER_H
