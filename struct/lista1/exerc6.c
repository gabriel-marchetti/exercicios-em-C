#define M 100
#include <stdio.h>
#include <stdlib.h>

typedef struct _aluno{
    int mat;
    char nome[M];
    float p1;
    float p2;
    float p3;
} aluno;


int main(void)
{
    FILE *fp;
    fp = fopen("exerc6.txt", "r");
    if ( fp == NULL ){
        printf("File not found.\n");
        return(-1);
    }

    aluno classe[5];
    for (int i = 0; i < 5; i++){
        fscanf(fp, "%d ", &(classe[i].mat));
        fgets(classe[i].nome, M, fp);
        fscanf(fp, "%f ", &(classe[i].p1));
        fscanf(fp, "%f ", &(classe[i].p2));
        fscanf(fp, "%f", &(classe[i].p3));
    }

    return(0);
}