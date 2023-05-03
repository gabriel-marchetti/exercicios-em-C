#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("exerc5.txt", "r");

    if (fp == NULL){
        printf("Não consegui ler o arquivo.\n");
        return(-1);
    }

    int n;
    fscanf(fp, "%d", &n);

    int *V = (int *)calloc(n, sizeof(int));
    

    return(0);
}