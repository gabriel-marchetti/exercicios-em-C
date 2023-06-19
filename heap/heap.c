#ifndef __HEAP__
#define __HEAP__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*--DEFINE-MACROS--*/

#define leftchild(parent) (2*parent+1)
#define rightchild(parent) (2*parent+2)
#define parent(child) ( (int)child/2 - 1 )

/*----------------*/


/*--Estruturas-de-dados--*/

typedef struct _arvbin{
    int info;
    struct _arvbin *left, *right;
} bintree, nodeTree;


typedef struct _linkedList{
    int info;
    struct _linkedList *next;
} linkedlist;


typedef struct _heap{
    int tamMax, tam;
    int *array[];
} heap;

/*-----------------------*/

/*--Espaço das Funções--*/

void swap(int **array, int p1, int p2)
{
    int aux = (*array)[p2];
    (*array)[p2] = (*array)[p1];
    (*array)[p1] = aux;
}


void MaxHeapify(heap *H, int i)
{
    int LChild = leftchild(i), RChild = rightchild(i);
    if ( LChild >= H->tam ) return;
    else {
        int largest = i;
        if ( (H->array)[LChild] > (H->array)[largest] ) largest = LChild;
        if ( (H->array)[RChild] > (H->array)[largest] ) largest = RChild;

        if ( largest != i ){
            swap(&(H->array), largest, i);
            MaxHeapify(H, largest);
        }
    }
}


void MinHeapify(heap *H, int i)
{
    int LChild = leftchild(i), RChild = rightchild(i);
    if ( LChild >= H->tam ) return;
    else {
        int smallest = i;
        if ( (H->array)[LChild] < (H->array)[smallest] ) smallest = LChild;
        if ( (H->array)[LChild] < (H->array)[smallest] ) smallest = RChild;
    }
}


int augmentArray(heap **Heap)
{
    int newSize = 2 * (*Heap)->tam;
    int *newArray = realloc(*((*Heap)->array), newSize * sizeof(int));
    if ( newArray == NULL ){
        printf("Falha ao alocar a memória.\n");
        return 0;
    }
    
    *((*Heap)->array) = newArray;
    (*Heap)->tamMax = newSize;
    return 1;
}


heap *initializeHeap()
{
    heap *H = (heap *)calloc(1, sizeof(heap));
    int array[1000];
    H->tamMax=1000;
    H->tam=0;
    *(H->array) = array;

    return H;
}


void addLinkedList(linkedlist **ll, int info)
{
    linkedlist *addNode = (linkedlist *)calloc(1, sizeof(linkedlist));
    addNode->info = info;
    addNode->next = NULL;
    linkedlist *current = *ll;
    if ( *ll == NULL ){
        (*ll) = addNode;
    } else {
        while ( current->next != NULL ){
            current = current->next;
        } 
        current->next = addNode;
    }
}


void printLinkedList(linkedlist *ll)
{
    while( ll != NULL ){
        printf("%d ", ll->info);
        ll = ll->next;
    }
    printf("\n");
}


bintree *createTreeWithHeap(heap *H, int k)
{
    if ( k >= H->tam  ) return NULL;
    /* Pensemos no Heap [8,4,6,3,1,2,5] notemos que queremos montar a partir do indice k=0 até k=6.*/
    /* Desse modo o k não pode ter o valor 7, por exemplo, por isso retorna NULL nesse caso.*/
    bintree *T = (bintree *)calloc(1, sizeof(bintree));
    T->info = (H->array)[k]; 
    T->left = createTreeWithHeap(H, leftchild(k));
    T->right = createTreeWithHeap(H, rightchild(k));

    return T;
}


void printBinaryTree(bintree *T, int h)
{
    /*
    T: Binary Tree
    h: Current Tree Height. Starts with zero if you want to print it!
    */
    if ( T != NULL ){
        printBinaryTree(T->right, h+1);
        for(int i=0; i < h; i++) printf("   ");
        printf("%d", T->info);
        printf("\n");
        printBinaryTree(T->left, h+1);
    }
}

/*---------------------*/


/* Função Main: Corpo Principal */
int main(int argc, char *argv[])
{
    /*---Variáveis---*/

    FILE *file=NULL;
    int condition, continuar=1, n, insere;
    char filename[50];
    heap *Heap = initializeHeap();
    linkedlist *ll = NULL;

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
        printf("10 - Heap como arvore. \n");
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
            printf("Qual o .txt para criar a lista ligada: "); scanf("%s", filename);
            file = fopen(filename, "r");
            if ( file == NULL ) printf("Não consegui encontrar o arquivo.\n");
            fscanf(file, "%d", &n);
            for( int i = 0; i < n; i++){
                fscanf(file, "%d", &insere);
                addLinkedList(&ll, insere);
            }
            // printLinkedList(ll);
            // Deu certo colocar a linkedList do .txt!
            /* Agora preciso fazer o processo de Heapify de uma linkedList. */
            
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