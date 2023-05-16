#define SIZE 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Implementing a Stack with an array. */

void push(int stack[SIZE], int elem, int *pos);
void pop(int stack[SIZE], int *pos);
bool checkEmpty(int stack[SIZE], int *pos);
void printStack(int stack[SIZE], int *pos);
bool searchElement(int stack[SIZE],int elem,  int *pos);


int main(void)
{
    int stack[SIZE], top = 0, num, caso;

    bool process = true, empty = true, aux;
    while( process ){
        printf("1 - Push element.\n");
        printf("2 - Pop element.\n");
        printf("3 - Is empty.\n");
        printf("4 - Print Stack.\n");
        printf("5 - Search element.\n");

        scanf("%d", &caso);
        switch(caso){
            case 1:
                printf("Insert element: "); scanf("%d", &num);
                push(stack, num, &top);
                empty = false;
                break;
            case 2:
                printf("Remove element.\n");
                pop(stack, &top);
                if ( top == 0 ){
                    empty = true;
                }
                break;
            case 3:
                empty = checkEmpty(stack, &top);
                if ( empty ){
                    printf("Is empty.\n");
                } else {
                    printf("Not empty.\n");
                }
                break;
            case 4:
                printStack(stack, &top);
                break;
            case 5:
                printf("Type element: "); scanf("%d", &num);
                aux = searchElement(stack, num, &top);
                if ( aux ){
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
            default:
                process = false;
                break;
        }
    }

    return(0);
}


void push(int stack[SIZE], int elem, int *pos)
{
    if ( *pos == SIZE - 1){
        printf("The stack is full.\n");
    } else {
        stack[*pos] = elem;
        (*pos)++;
    } 
}


void pop(int stack[SIZE], int *pos)
{
    if ( *pos == 0 ){
        printf("The stack is empty.\n");
    } else {
        (*pos)--;
    }
}


bool checkEmpty(int stack[SIZE], int *pos)
{
    if (*pos == 0){
        return(true);
    } else {
        return(false);
    }
}


void printStack(int stack[SIZE], int *pos)
{
    for ( int i = 0; i < *pos - 1 ; i++){
        printf("%d -- ", stack[i]);
    }
    printf("%d\n", stack[*pos - 1]);
}


bool searchElement(int stack[SIZE],int elem,  int *pos)
{
    for ( int i = 0; i < *pos; i++){
        if(stack[i] == elem) return(true);
    }
    return(false);
}

