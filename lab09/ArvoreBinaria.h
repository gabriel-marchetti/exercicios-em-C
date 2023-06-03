#ifndef __ArvBin__
#define __ArvBin__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define TAM_MAX 100

typedef struct _arvbin{
    int info;
    struct _arvbin *esq, *dir;
} arvbin, nodeArvbin;

void createTree(arvbin **T);
arvbin *createNode(int info);
arvbin *createTreeSimPos(int *sim, int *pos, int n);
int searchPos(int *array, int n, int wanted);
void printBinaryTree(arvbin *T, int h);

#endif