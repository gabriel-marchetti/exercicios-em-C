#include <stdio.h>
#include <stdlib.h>
#define MAX 6


void buscaMaior(int A[][MAX], int n, int *maior, int *lin, int *col, int *cond){
    if(A[*lin][*col] > *maior){
        *maior = A[*lin][*col];
    }
    if ( *lin < n){
        *lin = *lin + 1;
    } else if (*col < n) {
        *col = *col + 1;
    } else {
        *cond = 1;
    }
}


int main(){
    int A[MAX][MAX];

    char *filename = "t.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Error: could't find the file %s\n", filename);
        return(-1);
    }

    int n;
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(fp, "%d", &A[i][j]);
        }
    }

    int maior, lin, col, cond;
    maior = A[0][0]; lin = 0; col = 0; cond = 1;
    while (cond == 1){
        buscaMaior(A, n, &maior, &lin, &col, &cond);
    }
    
    printf("O maior elemento %d esta na linha %d e coluna %d\n", maior, lin, col);

    return(0);
}