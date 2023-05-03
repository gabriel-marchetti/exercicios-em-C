#include <stdio.h>
#include <stdlib.h>


void metodo(int *lista, int dim, int *menor, int *maior)
{
    for (int i = 0; i < dim; i++){
        if (lista[i] > *maior){
            *maior = lista[i];
        }
        if (lista[i] < *menor){
            *menor = lista[i];
        }
    }
}


int main(void)
{
    FILE *fp;
    fp = fopen("input7.txt", "r");

    if (fp == NULL){
        printf("Não encontrei o arquivo.\n");
        return(-1);
    }

    int n;
    fscanf(fp, "%d", &n);
    int *vetor = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        fscanf(fp, "%d", &vetor[i]);
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("n = %d\n", n);

    int *maior = (int *)calloc(1, sizeof(int)), *menor = (int *)calloc(1, sizeof(int));
    *maior = vetor[0]; *menor = vetor[0];
    metodo(vetor, n, menor, maior);
    printf("Maior: %d \t Menor: %d \n", *maior, *menor);


    free(maior); free(menor); free(vetor);
    return(0);
}