#include "FuncPointersForAttacksInvokeH/FunctionsPtrAttackingUnits.h"

//pointer to the Phoenix attack
void (*fPtrPhoenix)(struct Phoenix *, Vector *, size_t) = &currentAttackingPhoenix;

// pointer to the Carrier attack
void (*fPtrCarrier)(struct Carrier *, Vector *, size_t) = &currentAttackingCarrier;

// pointer to the Viking attack
void (*fPtrViking)(struct Viking *, Vector *, size_t) = &currentAttackingViking;

// pointer to the Battle Cruiser attack.
void (*fPtrBattleCruiser)(struct BattleCruser *, Vector *, size_t) = &currentAttackingBC;

// pointer to the BroodLord attack
void (*fPtrBroodLord)(struct BroodLord *, Vector *, size_t) = &currentAttackingBroodLord;

// pointer to the Mutalisk attack.
void (*fPtrMutalisk)(struct Mutalisk *, Vector*, size_t) = &currentAttackingMutalisk;

void (**fPtrAttackingUnitsArray[6])() = { &fPtrBattleCruiser,
                                          &fPtrViking,
                                          &fPtrCarrier,
                                          &fPtrPhoenix,
                                          &fPtrMutalisk,
                                          &fPtrBroodLord};
