#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct _stack{
    char value;
    struct _stack *next;
} stack, nodeStack;

/* Declaração das funções */


stack *STACKinit( char elem );
void STACKpush( stack **pilha, char elemAd );
char STACKpop( stack **pilha );
void STACKdestroy( stack **pilha );
void STACKprint( stack *pilha );


/* MAIN */
int main(int argc, char *argv[])
{
    stack *pile = NULL, *pile2 = NULL;
    FILE *file;
    file = fopen("test2.txt", "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    char string[MAX];
    fgets(string, MAX, file);

    for ( int i = 0; string[i] != '\0' && string[i] != '\n'; i++ ){
        if ( string[i] == ' '){
            continue;
        } else {
            STACKpush(&pile, string[i]);
        }
    }
    STACKprint(pile);
    printf("\n");

    while ( pile != NULL ){
        STACKpush(&pile2, STACKpop(&pile));
    }
    STACKprint(pile2);
    printf("\n");
    
    STACKdestroy(&pile);
    fclose(file);
    return 0;
}

/* Corpo das funções */


stack *STACKinit( char elem )
{
    stack *p    = (stack *)calloc(1, sizeof(stack));
    p->value    = elem;
    return p;
}


void STACKpush( stack **pilha, char elemAd )
{
    stack *nodeAd = STACKinit(elemAd), *auxiliar = *pilha;

    if ( *pilha == NULL ){
        *pilha          = STACKinit(elemAd);
        (*pilha)->next  = NULL;
    } else {
        nodeAd->next    = *pilha;
        (*pilha)        = nodeAd;
    }
}


char STACKpop( stack **pilha )
{
    if ( *pilha == NULL){
        printf("Pilha Vazia.\n");
        return '\0';
    }

    char retorno;
    retorno     = (*pilha)->value;
    (*pilha)    = (*pilha)->next;
    
    return retorno;
}


void STACKdestroy( stack **pilha )
{
    stack *aux;
    while ( (*pilha) != NULL ){
        aux         = *pilha;
        (*pilha)    = (*pilha)->next;
        free(aux); 
    }
}


void STACKprint( stack *pilha )
{
    while ( pilha != NULL ){
        printf("%c ", pilha->value);
        pilha = pilha->next;
    }
}