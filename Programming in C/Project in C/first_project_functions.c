
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "first_project_functions.h"


typedef struct TDListNode {

      int m_nValue;

      struct TDListNode* m_pNextNode;

      struct TDListNode* m_pPrevNode;

    } TDListNode;

//this link always point to first Link
TDListNode *head = NULL;

//this link always point to last Link
TDListNode *last = NULL;


//checks if the list is empty
int isEmpty() {
   return head == NULL;
}

void insertAtFirstPositionElement(int value) {

   //creates node
   TDListNode *node = (TDListNode*) malloc(sizeof(TDListNode));

   node->m_nValue=value;


   if(isEmpty()) {
      //makes last node
      last = node;
   } else {
      //updates prev node
      head->m_pPrevNode = node;
   }

   //points so the old node becomes the new head
   node->m_pNextNode = head;

   //points the new to first node
   head = node;
}

TDListNode* removeNodeUsingValue(int value) {

   //so i can start from 0
   TDListNode* current = head;
   TDListNode* previous = NULL;

   //if list is empty
   if(isEmpty()) {
      return NULL;
   }

   //goes to the last elem in the list
   while(current->m_nValue!=value )
   {

      //checks if its last if its not returns nothing
      if(current->m_pNextNode == NULL)
      {
         return NULL;
      }

      else
      {
         //remembers where we are at
         previous = current;

         //goes forward
         current = current->m_pNextNode;
      }
   }
   //finds match and updates the connections
   if(current == head)
   {
      //makes first node to point the next
      head = head->m_pNextNode;

   }

   else
   {
      //skips the current node so it points the next (fixes the connection of the elements)
      current->m_pPrevNode->m_pNextNode = current->m_pNextNode;
   }

   if(current == last)
   {
      //last point goes backwards so it points properly
      last = current->m_pPrevNode;
   }
   else
   {
      current->m_pNextNode->m_pPrevNode = current->m_pPrevNode;
   }

   return current;
}

void printElements() {

   //starts from 0th elem
   TDListNode *node = head;

   //goest forward
   printf("\n -- ");

   while(node != NULL) {
      printf("%d ",node->m_nValue);
      node = node->m_pNextNode;
   }

   printf(" --");
}
//does what it says it does
void freePointers(TDListNode* node)
{

    while (node != NULL) {
    TDListNode *next = node->m_pNextNode;
    free(node);
    node = next;
  }
}

