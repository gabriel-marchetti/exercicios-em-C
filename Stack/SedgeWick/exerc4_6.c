#include "stack.h"
#include <stdio.h>
#define MAX 100

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen("test1.txt", "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return(-1);
    }

    stack *Q = NULL;
    char save, string[MAX];

    int lenght = 0;
    while(!feof(file)){
        fgets(string, MAX, file);
        //printf("%s", string);
    }

    for ( int i = 0; string[i] != '\0' && string[i] != '\n'; i++){
        if ( string[i] == '*'){
            // printf("Processo A\n");
            save = STACKpop(&Q, &lenght);
            printf("*  %c \t", save); STACKprint(Q);
        } else if (string[i] == ' '){
            continue;
        } else {
            // printf("Processo B\n");
            printf("%c \t", string[i]);
            STACKpush(&Q, string[i], &lenght);
            STACKprint(Q);
        }
    }


    return(0);
}


stack *STACKinit(char elem)
{
    stack *s    = (stack *)calloc(1, sizeof(stack));
    s->elem     = elem;
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

    while ( aux != NULL ){
        printf("%c ", aux->elem);
        aux = aux->next;
    }
    printf("\n");
}
