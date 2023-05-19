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


stack *STACKinit(char elem)
{
    stack *s    = (stack *)calloc(1, sizeof(stack));
    s->elem = elem;
    return(s);
}


int STACKempty(stack *s)
{
    if ( s == NULL ){
        return(1);
    } else {
        return(0);
    }
}


void STACKpush(stack **s, char elem, int *lenght)
{
    stack *q = (stack *)calloc(1, sizeof(stack));
    if ( *s == NULL ){
        q       = STACKinit(elem); 
        *s      = q;
        (*lenght)++;
    } else {
        q->elem     = elem;
        q->next     = *s;
        *s          = q;
        (*lenght)++;
    }
}


char STACKpop(stack **s, int *length)
{
    char aux;
    if ( *s == NULL ){
        printf("Empty Stack.\n");
    } else {
        if ((*s)->next == NULL ){
            aux     = (*s)->elem;
            *s      = NULL;
            *length = 0;
            return(aux);
        } else {
            aux     = (*s)->elem;
            *s      = (*s)->next;
            (*length)--;
            return(aux);
        }
    }
}


void STACKprint(stack *Q)
{
    stack *aux = Q;
    while (aux->next != NULL){
        printf("%c ", aux->elem);
        aux = aux->next;
    }
    printf("%c", aux->elem);
}


#endif