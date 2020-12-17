// linkedlist.h 
  
#ifndef LINKED_LIST_H 
#define LINKED_LIST_H 

#include <stdio.h>

typedef struct element
{
    int number;
    struct element *next;
    struct element *previous;
}List;


List *NewListElement(int unit);
void InputElementInAscendingList(List **head, List **tail, int unit);
int IsWordADigit (char *word);
void SortTextForList(FILE **fPointerReading, List **head, List **tail);
void PrintListWithRecursion(List *head);
//void CheckIfRightPosition();
#endif 