#include "FuncPointersForDefenceInvokeH/FunctionsPtrDamageReceiveUnits.h"

// pointer to phoenix damage receive.
void (*fPtrDamagePhoenixReceived)(struct Phoenix *, int16_t) = &damageReceivedPhoenix;

// pointer to damage received viking.
void (*fPtrDamageVikingReceived)(struct Viking *, int16_t) = &damageReceivedViking;

// pointer to the damage received battle cruiser
void (*fPtrDamageBattleCruserReceived)(struct BattleCruser *, int16_t) = &damageReceivedBattleCruser;

// pointer to te damage received carrier
void (*fPtrDamageCarrierReceived)(struct Carrier *, int16_t) = &damageReceivedCarrier;

// pointer to te damage received mutalisk
void (*fPtrDamageMutaliskReceived)(struct Mutalisk *, int16_t) = &damageTakenMutalisk;

// pointer to te damage received broodlord
void (*fPtrDamageBroodLordReceived)(struct BroodLord *, int16_t) = &damageReceivedBroodLord;

void (**fPtrDmgReceiveUnitArray[6])() = {(void (**)()) &fPtrDamageBattleCruserReceived,
                                         (void (**)()) &fPtrDamageVikingReceived,
                                         (void (**)()) &fPtrDamageCarrierReceived,
                                         (void (**)()) &fPtrDamagePhoenixReceived,
                                         (void (**)()) &fPtrDamageMutaliskReceived,
                                         (void (**)()) &fPtrDamageBroodLordReceived};