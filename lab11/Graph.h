#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*==DEFINING_MACROS==*/

#define NIL -1
#define INT_MAX 400

/*============*/

/*==DEFINING_DATA_STRUCTURES==*/

typedef struct _nodeGraph{
    int pred, custo;
    int label, nviz, visitado;
    int vizinhos[9];
} nodeGraph;

typedef struct _Fila{
    int size, maxSize;
    int *Queue;
} fila;

/*==PROTOTIPAGEM==*/
int **createMatrix(int size);
void printMatrix(int **matrix, int size);
void Questao1(nodeGraph **grafo, int label, int pred, int custo, int **arr, int **arr2);
void printArray(int arr[], int size);

/*================*/
#endif