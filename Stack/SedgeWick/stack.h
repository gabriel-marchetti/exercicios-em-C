#ifndef STACK_
#define STACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _stack{
    char elem;
    struct _stack *next;
} stack, newItem;

stack *STACKinit(char elem);
int STACKempty(stack *s);
void STACKpush(stack **s, char elem, int *lenght);
char STACKpop(stack **s, int *length);
void STACKprint(stack *Q);


#endif