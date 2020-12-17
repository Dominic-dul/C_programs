#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"
int main()
{
    printf ("This code test the insert in the list function\n");

    int wrong = 0;
    List *head = NULL, *tail = NULL;

    InputElementInAscendingList(&head, &tail, 5);
    assert(head->previous == NULL);
    assert(head->next == NULL);
    assert(head->number == 5);
    printf ("Element was inserted successfully, when inserting in the empty list\n");
    InputElementInAscendingList(&head, &tail, 10);
    assert(tail->next == NULL);
    assert(tail->number == 10);
    assert((tail->previous->number) < (tail->number));
    printf ("Element was inserted in the end successfully\n");
    InputElementInAscendingList(&head, &tail, 2);
    assert(head->previous == NULL);
    assert(head->number == 2);
    assert((head->next->number) > (head->number));
    printf("Element was inserted in the beginning successfully\n");
    InputElementInAscendingList(&head, &tail, 7);
    
    List *temp = head;
    while (temp != NULL)
    {
        if(temp->next != NULL && ((temp->number) > (temp->next->number)))
        {
            wrong++;
        }
        temp = temp->next;
    }
    assert(wrong == 0);
    printf("Element was put in the middle of the list successfully\n");

    printf("List is:\n");
    PrintListWithRecursion(head);
    return 0;
}