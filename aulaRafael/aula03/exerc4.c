#include <stdio.h>
#define MAX 5


void imprimeMatrix(double M[][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%f ", M[i][j]);
        }       
        printf("\n");
    }
}


void leMatrix(double M[][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &M[i][j]);
        }
    }
}


void multiplicaMatrix(  double A[][MAX], double B[][MAX],
                        double C[][MAX], int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
}


int main(){
    int n;
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Escreva o rank do problema: ");
    scanf("%d", &n);

    leMatrix(A, n);
    leMatrix(B, n);
    multiplicaMatrix(A, B, C, n);
    imprimeMatrix(C, n);

    return(0);
}