#ifndef _FILAPRIORIDADE_H_
#define _FILAPRIORIDADE_H_

/*--Bibliotecas--*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100 
#define leftchild(parent) (2*parent + 1)
#define rightchild(parent) (2*parent + 2)
#define parent(child) ( (int)child/2 -1 )

/*--------------*/

/*--Define-Estruturas--*/

typedef struct _client{
    int priority;
    char *name;
} client;


typedef struct _clientheap{
    int size;
    client fila[100];
} clientheap;

/*--------------------*/

/*-----PROTOTIPAGEM-----*/

void insertMaxHeap(clientheap **order, client new);
void insertMinHeap(clientheap **order, client new);




/*------------------------*/

#endif