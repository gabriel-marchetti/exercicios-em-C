#include <stdio.h>
#include <stdlib.h>


typedef struct _arvbin{
    int info;
    struct _arvbint *esq, *dir;
} arvbin, nodeArvbin;


/*---------------------------*/
/*DEFININDO AS FUNCOES UTEIS*/



/*----Funções-Auxiliares----*/
void printArray(int *array, int tamanho);
void hello();
/***************************/