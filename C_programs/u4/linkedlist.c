#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

List *NewListElement(int unit)
{
    List *el =(List*)malloc(sizeof(List));

    assert (el != NULL);

    el->number = unit;
    el->next = NULL;
    el->previous = NULL;

    return el;
}
void InputElementInAscendingList(List **head, List **tail, int unit)
{
    List *newElement = NewListElement(unit);

    if ((*head) == NULL)
    {
        (*head) = newElement;
        (*tail) = newElement;
        (*head)->previous = NULL;
        return;
    }

    if ((newElement->number) < ((*head)->number))
    {
        newElement->previous = NULL;
        (*head)->previous = newElement;
        newElement->next = (*head);
        (*head) = newElement;
        return;
    }

    if ((newElement->number) > ((*tail)->number))
    {
        newElement->previous = (*tail);
        (*tail)->next = newElement;
        (*tail) = newElement;
        return;
    }

    List *temp = (*head)->next;
    while ((temp->number) < (newElement->number))
    {
        temp = temp->next;
    }

    (temp->previous)->next = newElement;
    newElement->previous = temp->previous;
    temp->previous = newElement;
    newElement->next = temp;

    return;   
}
int IsWordADigit (char *word)
{
    if (strspn(word, "0123456789") == strlen(word)) return 1;
    else if (word[0] == '-')
    {
        if (strspn(word, "0123456789") == strlen(word)-1) 
        {
            return 1;
        }
    }
    else return 0;
}
void SortTextForList(FILE **fPointerReading, List **head, List **tail)
{
    char *line = calloc(255, sizeof(char)), *word;

    assert (line != NULL);

    int num, truth;

    while (fgets(line, 255,*fPointerReading) != NULL)
    {
        word = strtok(line, " \n");

        if (word != NULL)
            {
                truth = IsWordADigit(word);
                if(truth)
                {
                    num = atoi(word);
                    assert (num < INT_MAX);
                    assert (num > INT_MIN);
                    InputElementInAscendingList(head, tail, num);
                }              
            }
            
        do
        {
            word = strtok(NULL, " \n");
            if (word != NULL)
            {
                truth = IsWordADigit(word);
                if(truth)                
                {
                    num = atoi(word);
                    InputElementInAscendingList(head, tail, num);
                }
                
            }
        }while (word != NULL);
        
    }

    free(line);
}
void PrintListWithRecursion(List *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%d ", head->number);
    PrintListWithRecursion(head->next);
}