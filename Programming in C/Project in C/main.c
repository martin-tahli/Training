//22.Двойно-свързан списък. Напишете програма,
//която добавя и изтрива елемент от списъка по зададена
//стойност, която се пази в него.
//Използвайте следния елемент на двойно-свързания списък:
//
//    /* doubly linked list */
//
//    typedef struct TDListNode {
//
//      int m_nValue;
//
//      struct TDListNode* m_pNextNode;
//
//      struct TDListNode* m_pPrevNode;
//
//    } TDListNode;


//#include "first_project_functions.h"
#include "first_project_functions.c"



int main()
{

insertAtFirstPositionElement(1);
insertAtFirstPositionElement(2);
insertAtFirstPositionElement(3);
insertAtFirstPositionElement(4);
insertAtFirstPositionElement(5);
insertAtFirstPositionElement(6);
insertAtFirstPositionElement(7);

removeNodeUsingValue(4);

printElements();


freePointers(head);


return 0;
}


