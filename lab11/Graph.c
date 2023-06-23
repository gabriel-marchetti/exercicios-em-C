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
    for(int i = 0; i < size; i++) printf("%d ", arr[size]);
    printf("\n");
}

void insereFila(fila *Q, int inserido)
{
    Q->size = Q->size + 1;
    
}