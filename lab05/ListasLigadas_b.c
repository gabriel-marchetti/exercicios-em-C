#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _polinomio {
    float coef;
    int exp;
    struct _polinomio *prox;
} polinomio, noPolinomio;


int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("Couldn't find the file\n");
        return(-1);
    }

    int n;
    fscanf(fp, "%d", &n);
    polinomio *pol = criaPolinomio();
    
    float auxCoef;
    int auxExp;
    fscanf(fp, "%f %d ", &auxCoef, &auxExp);
    pol->coef = auxCoef;
    pol->exp = auxExp;
    while( !(feof(fp)) ){
        fscanf(fp, "%f %d ", &auxCoef, &auxExp);
        inserePolinomioHierarquico(&pol, auxCoef, auxExp);
    }
    imprimePolinomio(pol);

    return(0);
}