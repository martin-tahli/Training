#ifndef STARCRAFT_FUNCTIONSPTRATTACKINGUNITS_H
#define STARCRAFT_FUNCTIONSPTRATTACKINGUNITS_H

#include "CurrentAttackingUnitsH/CurrentAttackingViking.h"
#include "CurrentAttackingUnitsH/CurrentAttackingBattleCruiser.h"
#include "CurrentAttackingUnitsH/CurrentAttackingPhoenix.h"
#include "CurrentAttackingUnitsH/CurrentAttackingCarrier.h"
#include "CurrentAttackingUnitsH/CurrentAttackingMutalisk.h"
#include "CurrentAttackingUnitsH/CurrentAttackingBroodLord.h"


#include "Vector.h"

extern void (*fPtrPhoenix)(struct Phoenix *, Vector *, size_t);

extern void (*fPtrCarrier)(struct Carrier *, Vector *,size_t );

extern void (*fPtrViking)(struct Viking *, Vector *, size_t) ;

extern void (*fPtrBattleCruiser)(struct BattleCruser *, Vector *, size_t) ;

extern void (*fPtrBroodLord)(struct BroodLord *,Vector *, size_t) ;

extern void (*fPtrMutalisk)(struct Mutalisk *, Vector *, size_t) ;



#endif //STARCRAFT_FUNCTIONSPTRATTACKINGUNITS_H
