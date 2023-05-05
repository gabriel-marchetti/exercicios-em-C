#include <stdio.h>
#include <stdlib.h>

typedef struct _polinomio {
    float coef;
    int exp;
    struct _polinomio *prox;
} polinomio, noPolinomio;


polinomio *criaPolinomio()
{
    noPolinomio *termo = (noPolinomio *)calloc(1, sizeof(polinomio));
}


noPolinomio *criaNoPolinomio(float coef, int exp)
{
    noPolinomio *no = (noPolinomio *)calloc(1, sizeof(noPolinomio));
    no->coef = coef;
    no->exp = exp;
    no->prox = NULL;
    return(no);
}


void inserePolinomio(polinomio *pol, float coef, int exp)
{
    noPolinomio *termoAdicionar = criaNoPolinomio(coef, exp),*termo = pol;
    while (termo->prox != NULL){
        termo = termo->prox;
    }
    termo->prox = termoAdicionar;
}


void inserePolinomioHierarquico(polinomio **pol, float coef, int exp)
{
    noPolinomio *termoAdicionar = criaNoPolinomio(coef, exp), *termo = *pol, *termo_ant = NULL;
    if ( termo->exp < termoAdicionar->exp ){
        termoAdicionar->prox    = termo;
        *pol                    = termoAdicionar;
        return;
    }
    while( termo->prox != NULL ){
        if( termo->exp > termoAdicionar->exp ){
            termo_ant   = termo;
            termo       = termo->prox;
        } else {
            termo_ant->prox         = termoAdicionar;
            termoAdicionar->prox    = termo;
            return;
        }
    }
    if ( termo->exp < termoAdicionar->exp ){
        termo_ant->prox = termoAdicionar;
        termoAdicionar->prox = termo;
    } else {
        termo->prox = termoAdicionar;
    }
}


void imprimePolinomio(polinomio *pol)
{
    noPolinomio *termo = pol;
    while(termo->prox != NULL){
        printf("+ %.2fx^%d ", termo->coef, termo->exp);
        termo = termo->prox;
    }
    printf("+ %.2fx^%d\n", termo->coef, termo->exp);
}


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