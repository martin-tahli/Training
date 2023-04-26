#ifndef STARCRAFT_FUNCTIONSPTRDAMAGERECEIVEUNITS_H
#define STARCRAFT_FUNCTIONSPTRDAMAGERECEIVEUNITS_H

#include "WarUnitsH/BattleCruser.h"
#include "WarUnitsH/Carrier.h"
#include "WarUnitsH/Viking.h"
#include "WarUnitsH/Phoenix.h"
#include "WarUnitsH/Mutalisk.h"
#include "WarUnitsH/BroodLord.h"

extern void (*fPtrDamagePhoenixReceived)(struct Phoenix *, int16_t);

extern void (*fPtrDamageVikingReceived)(struct Viking *, int16_t);

extern void (*fPtrDamageBattleCruserReceived)(struct BattleCruser *, int16_t);

extern void (*fPtrDamageCarrierReceived)(struct Carrier *, int16_t);

extern void (*fPtrDamageMutaliskReceived)(struct Mutalisk *, int16_t);

extern void (*fPtrDamageBroodLordReceived)(struct BroodLord *, int16_t);

extern void (**fPtrDmgReceiveUnitArray[6])(struct basicUnit*, size_t);

#endif //STARCRAFT_FUNCTIONSPTRDAMAGERECEIVEUNITS_H
