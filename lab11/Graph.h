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

typedef struct _linkedlist{
    int info;
    struct _linkedlist *next;
} linkedlist;

typedef struct _Fila{
    int size, maxSize;
    linkedlist *head, *tail;
} fila;

/*==PROTOTIPAGEM==*/
int **createMatrix(int size);
void printMatrix(int **matrix, int size);
// void Questao1(nodeGraph **grafo, int label, int pred, int custo, int **arr, int **arr2);
void printArray(int arr[], int size);
void insereFila(fila **Q, int inserido);
int removeFila(fila **Q);
void buscaLargura(nodeGraph **G, int current);


/*================*/
#endif