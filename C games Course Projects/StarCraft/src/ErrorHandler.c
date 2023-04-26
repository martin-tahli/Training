#include "ErrorHandler.h"


void printErrorStatus(int idx)
{
    switch(idx)
    {
        case 0:
            puts("\nError: Unable to allocate memory!\nCheck VectorInit function!");
            break;
        case 1:
            puts("\nError: Unable to allocate memory for BattleCruiser unit!");
            break;
        case 2:
            puts("\nError: Unable to allocate memory for Carrier unit!");
            break;
        case 3:
            puts("\nError: Unable to allocate memory for Phoenix unit!");
            break;
        case 4:
            puts("\nError: Unable to allocate memory for Viking unit!");
            break;
        case 5:
            puts("\nError: Unable to allocate memory for BroodLord unit!");
            break;
        case 6:
            puts("\nError: Unable to allocate memory for Mutalisk unit!");
            break;
        case 7:
            puts("\nThe winner has invalid race type!");


        default:
            break;
    }
}