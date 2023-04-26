#ifndef FIRST_PROJECT_FUNCTIONS_H
#define FIRST_PROJECT_FUNCTIONS_H



typedef struct TDListNode  TDListNode;


int isEmpty();

void insertAtFirstPositionElement(int value);

TDListNode* removeNodeUsingValue(int value);

void printElements();

void freePointers(TDListNode* node);

#endif
