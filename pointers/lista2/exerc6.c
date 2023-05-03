#include <stdio.h>
#include <stdlib.h>


void metodoMultiplica(int *lista, int dim)
{
    for (int i = 0; i < dim; i++){
        lista[i] = lista[i]*2;
    }
}


void imprimeLista(int *lista, int dim)
{
    for (int i = 0; i < dim; i++){
        printf("%d \t", lista[i]);
    }
    printf("\n");
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc6.txt", "r");

    if (fp == NULL){
        printf("Não consegui encontrar o arquivo.\n");
        return(-1);
    }

    int n;
    fscanf(fp, "%d", &n);

    int *V = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        fscanf(fp, "%d", &V[i]);
    }

    printf("Lista antes: \t"); imprimeLista(V, n);
    metodoMultiplica(V, n);    
    printf("Lista depois: \t"); imprimeLista(V, n);

    return(0);
}