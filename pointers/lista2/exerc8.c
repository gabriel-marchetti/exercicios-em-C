#include <stdio.h>
#include <stdlib.h>


void metodo(int **vetor, int *menor, int n, int *iter)
{
    if (*iter > n){
        return;
    } else {
        if ((*vetor)[*iter] < *menor){
            *menor = (*vetor)[*iter];
        }
        (*iter)++;
        metodo(vetor, menor, n, iter);
    }
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc8.txt", "r");

    if (fp == NULL){
        printf("Não consegui encontrar o arquivo.\n");
        return(-1);
    }

    int n;
    fscanf(fp, "%d", &n);
    printf("Tamanho da lista: %d\n", n);
    int *vetor = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        fscanf(fp, "%d", &vetor[i]);
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int *menor = (int *)calloc(1, sizeof(int));
    int *iter = (int *)calloc(1, sizeof(int));
    *menor = vetor[0];
    metodo(&vetor, menor, n, iter);
    printf("Menor da lista: %d\n", *menor);

    free(vetor);
    free(menor); free(iter);
    return(0);
}