#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _pilha{
    int value;
    struct _pilha *prox;
} pilha;


pilha *criaPilha(int elem);
void push(pilha **top, int elem, int *lenght);
void pop(pilha **top, int *lenght);
void printStack(pilha *top);
bool searchElement(pilha *top, int elem);


int main(void)
{
    pilha *top = NULL;
    int lenght = 0, option;
    bool condition, search;

    /* Quero colocar alguns elementos de teste. */
    FILE *file;
    file = fopen("exerc2.txt", "r");
    if (file == NULL){
        printf("Could't find the file.\n");
        return(-1);
    }
    
    int number;
    while (!(feof(file))){
        fscanf(file, "%d ", &number);
        push(&top, number, &lenght);
    }
    do{
        printf( "\nStack Menu\n1. Empilhar\n2. Desempilha\n3. Busca elemento\n"
                "4. Imprime Stack.\n0. Sair.\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Qual elemento adicionar: "); scanf("%d", &number);
                push(&top, number, &lenght);
                printf("Elemento adicionado!\n");
                break;
            case 2:
                printf("Desempilhando.\n");
                pop(&top, &lenght);
                printf("Desempilhado!.");
                break;
            case 3:
                printf("Qual elemento deseja buscar: "); scanf("%d", &number);
                search = searchElement(top, number);
                if (search){
                    printf("Está na Stack.\n");
                } else {
                    printf("Não está na Stack.\n");
                }
                break;
            case 4:
                printStack(top);
                break;
            default:
                condition = false;
                break;
        }
    } while (condition);
    

    return(0);
}


pilha *criaPilha(int elem)
{
    pilha *p    = (pilha *)calloc(1, sizeof(pilha));
    p->value    = elem;
    return(p);
}


void push(pilha **top, int elem, int *lenght)
{
    if ( *top == NULL ){
        *top = criaPilha(elem);
        return;
    }
    pilha *q = (pilha *)calloc(1, sizeof(pilha));
    q->value    = elem;
    q->prox     = *top;
    *top         = q;
    (*lenght)++;
}


void pop(pilha **top, int *lenght)
{
    pilha *p;
    if (*lenght == 0){
        printf("Stack vazia.\n");
        return;
    }
    p       = *top;
    *top    = (*top)->prox;
    (*lenght)--;
    free(p);
}


void printStack(pilha *top)
{
    if ( top->prox == NULL){
        printf("%d", top->value);
    } else {
        printf("%d -> ", top->value);
        printStack(top->prox);
    }
}


bool searchElement(pilha *top, int elem)
{
    if ( top->value == elem){
        return(true);
    } else {
        if (top->prox == NULL){
            return(false);
        } else {
            searchElement(top->prox, elem);
        }
    } 
}