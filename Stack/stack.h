#ifndef STACK_
#define STACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _stack{
    int elem;
    struct _stack *next;
} stack, newItem;

stack *STACKinit(int elem);
int STACKempty(stack *s);
void STACKpush(stack **s, int elem, int *lenght);
int STACKpop(stack **s, int *length);

#endif