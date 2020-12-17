//Program creates an ascending doubly linked list. There is a menu, where you can choose options, what do you want to do with your program
//Program also inserts given integer into the list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "linkedlist.h"
char *FileName()
{
    char *name = (char*)malloc(sizeof(char)*255);

    printf ("Enter file name:\n");
    scanf("%s", name);

    assert (name != NULL);

    return name;
}
void PrintMenu()
{
    printf ("\nProgram creates an ascending list from integers in given file. It can insert given number in the created list\n");
    printf ("Choose what do you want to do further with the program:\n");
    printf ("Press 0 to create a list from a file\n");
    printf ("Press 1 to print the created list\n");
    printf ("Press 2 to insert a number into the list\n");
    printf ("Press 3 to exit the program\n");
}

void NumberValidation(int *number)
{
    char character;
    while (scanf("%d%c", number, &character) == 0 || character != '\n')
    {
        scanf("%*[^\n]");
        printf ("Invalid input. Try again\n");
    }
}
int Input(List **head, List **tail)
{
    int number;    

    NumberValidation(&number);
    while (number < 0 || number > 3)
    {
        printf("Your inserted number is not between 0 and 3. Try again\n");
        NumberValidation(&number);
    }

    printf ("You chose to do %d\n", number);

    switch(number)
    {
        case 0:
            printf ("Creating a list form file\n");
            char *data;
            FILE *fPointerReading;
            data = FileName();
            fPointerReading = fopen(data, "r");
            SortTextForList(&fPointerReading, head, tail);
            return 1;         
        case 1:
            printf("Printing list:\n");
            PrintListWithRecursion(*head);
            return 1;
        case 2:
            printf ("Enter a number:\n");
            NumberValidation(&number);
            InputElementInAscendingList(head, tail, number);
            return 1;
        case 3:
            printf ("Exiting the program\n");
            exit(0);
        default:
            return 0;
    }
    
}
int main(){

    List *head = NULL, *tail = NULL;
    int close = 1;

    while(close)
    {
        PrintMenu();
        close = Input(&head, &tail);
    }

    return 0;
}