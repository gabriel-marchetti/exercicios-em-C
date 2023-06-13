#ifndef __HEAP__
#define __HEAP__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*--Estruturas-de-dados--*/

typedef struct _arvbin{
    int info;
    struct _arvbin *left, *right;
} bintree, nodeTree;


typedef struct _linkedList{
    int info;
    struct _arvbin *next;
} linkedlist;


typedef struct _heap{
    int tamMax, tam;
    int *array[];
} heap;

/*-----------------------*/

/*--Espaço das Funções--*/

void heapify()
{

}


int augmentArray(heap **Heap)
{
    int newSize = 2 * (*Heap)->tam;
    int *newArray = realloc(*((*Heap)->array), newSize * sizeof(int));
    if ( newArray = NULL ){
        printf("Falha ao alocar a memória.\n");
        return 0;
    }
    
    *((*Heap)->array) = newArray;
    (*Heap)->tamMax = newSize;
    return 1;
}

/*---------------------*/


/* Função Main: Corpo Principal */
int main(int argc, char *argv[])
{
    /*---Variáveis---*/

    FILE *file=NULL;
    int condition, continuar=1;
    heap *Heap;

    /*---------------*/

    while ( continuar ){
        /*--Condicao-Tamanho--*/
        /*-Quero criar uma condição que verifica o tamanho do array do heap.*/
        /*-Caso ele esteja muito cheio, crio um novo array e aloco para o heap.*/
        if ( Heap->tamMax - Heap->tam < 3 ){
            if ( augmentArray(&Heap) ) {
                printf("Processo de Aumento do Heap realizado.\n");
            } else {
                printf("Problema no Aumento do Heap...\n");
                return -1;
            }
        }

        // Options // 
        printf("----Operacoes----\n");
        printf("1 - Push no Heap.\n");
        printf("2 - Pop no Heap.\n");
        printf("3 - Peek no Heap.\n");
        printf("4 - Delete-max no Heap.\n");
        printf("5 - Heapify.\n");
        printf("6 - Merge no Heap.\n");
        printf("7 - Meld no Heap. \n");
        printf("8 - Size do Heap. \n");
        printf("9 - IsEmpty do Heap. \n"); 
        printf("99 - Parar \n");

        // Switch //
        printf("Qual opcao deseja realizar? ");
        fflush(stdin);
        scanf("%d", &condition);


        switch (condition){
        case 1:
            sleep(1.5);
            break;
        case 2:
            sleep(1.5);
            break;
        case 3:
            sleep(1.5);
            break;
        case 4:
            sleep(1.5);
            break;
        case 5:
            sleep(1.5);
            break;
        case 6:
            sleep(1.5);
            break;
        case 7:
            sleep(1.5);
            break;
        case 9:
            sleep(1.5);
            break;
        case 10:
            sleep(1.5);
            break;
        case 11:
            sleep(1.5);
            break;
        case 99:
            continuar = 0;
            break;
        default:
            printf("Nao tenho essa opcao.\n");
            sleep(1.5);
            break;
        }
        fflush(stdin);
    }
    return 0;
}
#endif