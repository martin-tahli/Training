#ifndef STARCRAFT_CURRENTATTACKINGBROODLORD_H
#define STARCRAFT_CURRENTATTACKINGBROODLORD_H


#include "WarUnitsH/BroodLord.h"
#include "Utility.h"
#include "FuncPointersForDefenceInvokeH/FunctionsPtrDamageReceiveUnits.h"


void currentAttackingBroodLord(struct BroodLord *currentAttackUnit, Vector *currentTeam, size_t indx);

#endif //STARCRAFT_CURRENTATTACKINGBROODLORD_H
