#ifndef STARCRAFT_BATTLE_H
#define STARCRAFT_BATTLE_H

#include <stdint.h>
#include "BattleField.h"
#include "UnitTypesStructuresH/TerranUnitType.h"
#include "UnitTypesStructuresH/BasicUnitType.h"
#include "UnitTypesStructuresH/ZergUnitType.h"
#include "Defines.h"
#include "CurrentAttackingUnitsH/CurrentAttackingPhoenix.h"
#include "CurrentAttackingUnitsH/CurrentAttackingCarrier.h"
#include "CurrentAttackingUnitsH/CurrentAttackingViking.h"
#include "CurrentAttackingUnitsH/CurrentAttackingBattleCruiser.h"
#include "CurrentAttackingUnitsH/CurrentAttackingBroodLord.h"
#include "CurrentAttackingUnitsH/CurrentAttackingMutalisk.h"

#include "FuncPointersForAttacksInvokeH/FunctionsPtrAttackingUnits.h"


int BATTLE(Vector * Team1, Vector * Team2);
extern void (**fPtrAttackingUnitsArray[6])(struct basicUnit*, Vector* , size_t);


#endif //STARCRAFT_BATTLE_H
