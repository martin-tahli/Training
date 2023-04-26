
#include "ErrorHandler.h"

void printErrorStatus(const int idx)
{
    switch(idx)
    {
        case 0:
            puts("\nError: Unable to allocate memory!\nCheck VectorInit function!");
            break;
        case 1:
            puts("\nError: Unable to allocate memory for ArchMage unit!");
            break;
        case 2:
            puts("\nError: Unable to allocate memory for Paladin unit!");
            break;
        case 3:
            puts("\nError: Unable to allocate memory for Death Knight unit!");
            break;
        case 4:
            puts("\nError: Unable to allocate memory for Draw Ranger!");
            break;
        case 5:
            puts("\nError: Unable to allocate memory for  Initializing hero!");
            break;
        default:
            break;
    }
}