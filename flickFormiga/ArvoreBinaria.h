#include <stdio.h>
#include <stdlib.h>


typedef struct _arvbin{
    int info;
    struct _arvbin *esq, *dir;
} arvbin, nodeArvbin;


/*---------------------------*/
/*DEFININDO AS FUNCOES UTEIS*/
arvbin *buildTree(int tamanho, int *sim, int *pos);
arvbin *createNodeTree(int info);
void printBinaryTree(arvbin *T, int h);


/*----Funções-Auxiliares----*/
void printArray(int *array, int tamanho);
void hello();
/***************************/