#include "Graph.h"

/*==DEFINING_FUNCTION==*/
int **createMatrix(int size)
{
    int **matrix = (int **)calloc(size, sizeof(int *));
    for(int i = 0; i < size; i++){
        matrix[i] = (int *)calloc(size, sizeof(int));
    }
    return (matrix);
}

void printMatrix(int **matrix, int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// void Questao1(nodeGraph **grafo, int label, int pred, int custo, int **arr, int **arr2)
// {
//     // arr: lista de predecessores.
//     // arr2: lista de custos.
//     // Primeira chamada
//     // Questao1(grafo, B, NIL, 0, &arr, &arr2 )
//     if ( (*grafo)[label].visitado ){ return; }
//     else {
//         (*grafo)[label].visitado = 1;
//         if ( (*grafo)[label].custo < custo ){
//             (*grafo)[label].custo = custo;
//         }
//         (*arr)[label] = pred;
//         (*arr2)[label] = custo;
//         int *listaVizinhos = (*grafo)[label].vizinhos;
//         int numVizinhos = (*grafo)[label].nviz, vizinho;
//         for (int i = 0; i < numVizinhos; i++){
//             vizinho = listaVizinhos[i];
//             Questao1(grafo, vizinho, label, custo + 1, arr, arr2);
//         }
//     }
// }

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insereFila(fila **Q, int inserido)
{   
    if ( (*Q)->size >= (*Q)->maxSize ){
        printf("Queue overflow.\n");
    } else {
        (*Q)->size++;
        linkedlist *new = (linkedlist *)calloc(1, sizeof(linkedlist));
        new->info = inserido;
        new->next = NULL;
        if ( (*Q)->head == NULL ){
            (*Q)->head  = new;
            (*Q)->tail  = new;
        } else {
            (*Q)->tail->next    = new;
            (*Q)->tail          = (*Q)->tail->next;
        }
    }
}

int removeFila(fila **Q)
{
    if ( (*Q)->head == NULL ) return -1;
    linkedlist *aux = (*Q)->head;
    int pop         = (*Q)->head->info;

    if ( (*Q)->head == (*Q)->tail ){
        aux = (*Q)->head;
        (*Q)->head = NULL;
        (*Q)->tail = NULL;
    } else {
        (*Q)->head = (*Q)->head->next;
    }
    (*Q)->size--;
    free(aux);
    return pop;
}

void buscaLargura(nodeGraph **G, int current)
{
    fila *Q = (fila *)malloc(sizeof(fila));
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;
    Q->maxSize = 20;
    // arr : Lista de predecessores.
    // arr2 : Lista de Custos.
    insereFila(&Q, 1);
    int custo = 1;
    (*G)[Q->head->info].custo = 0;
    (*G)[Q->head->info].pred = NIL;
    while ( Q->head != NULL ){
        int numVizinhos = (*G)[Q->head->info].nviz;
        for(int i = 0; i < numVizinhos; i++){
            int vizinhoAtual = ((*G)[Q->head->info].vizinhos)[i];
            if ( (*G)[vizinhoAtual].visitado ){
                continue;
            } else {
                insereFila(&Q, vizinhoAtual);
                (*G)[vizinhoAtual].visitado = 1;
                (*G)[vizinhoAtual].pred = Q->head->info;
                (*G)[vizinhoAtual].custo = custo;
            }
        }
        removeFila(&Q);
        custo++;
    }
}