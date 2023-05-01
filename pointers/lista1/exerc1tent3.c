#include <stdio.h>
#include <stdlib.h>

#define N 10


void imprimeMatriz(int A[][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
}


void MAXnew(int A[][N], int n, int *maior, int *linMAX, int *colMAX){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(A[i][j] > *maior){
                *maior = A[i][j];
                *linMAX = i;
                *colMAX = j;
            }
        }
    }
}


int main()
{
    FILE *fp;
    fp = fopen("test1.txt", "r");

    if( fp == NULL ){
        printf("Erro na abertura do .txt\n");
        return(1);
    }

    int n, A[N][N];
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(fp, "%d", &A[i][j]);
        }
    }
    
    int maior, linMAX, colMAX;
    maior = A[0][0]; linMAX = -1; colMAX = -1;
    MAXnew(A, n, &maior, &linMAX, &colMAX);
    
    imprimeMatriz(A, n);
    linMAX++; colMAX++; // incremento devido a indexação.
    printf("O maior elemento é %d na linha %d e coluna %d\n", maior, linMAX, colMAX);
    return(0);
}