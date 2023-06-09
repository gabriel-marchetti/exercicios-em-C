#include <stack.h>


stack  *STACKinit(int elem)
{
    stack *s    = (stack *)calloc(1, sizeof(stack));
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


void STACKpush(stack **s, int elem, int *lenght)
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


int STACKpop(stack **s, int *length)
{
    int aux;
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