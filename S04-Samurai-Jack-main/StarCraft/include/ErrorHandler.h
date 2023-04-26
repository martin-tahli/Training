
#ifndef STARCRAFT_ERRORHANDLER_H
#define STARCRAFT_ERRORHANDLER_H


#ifndef errorHandler_h
#define errorHandler_h

#include <stdio.h>

void printErrorStatus(int idx);


enum errorsCodeList {

    ERR_MMU_VECTOR_INIT = 0,
    ERR_ALLOCATE_BATTLE_CRUISER,
    ERR_ALLOCATE_CARRIER,
    ERR_ALLOCATE_PHOENIX,
    ERR_ALLOCATE_VIKING,
    ERR_ALLOCATE_BROODLORD,
    ERR_ALLOCATE_MUTALISK,
    ERR_IF_NOT_PROTOSS_TERRAN_ZERG
};





#endif /* errorHandler_h */
#endif //STARCRAFT_ERRORHANDLER_H
