#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _polinomio {
    float coef;
    int exp;
    struct _polinomio *prox;
} polinomio, noPolinomio;


polinomio *criaPolinomio()
{
    noPolinomio *termo = (noPolinomio *)calloc(1, sizeof(polinomio));
    return(termo);
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


void derivaPolinomioa(polinomio **pol)
{
    noPolinomio *termo = *pol, *termo_ant = NULL;
    if (*pol == NULL){
        return;
    }
    while (termo->prox != NULL){
        if( termo->exp == 0){
            termo_ant->prox = termo->prox;
            termo_ant = termo;
            termo = termo->prox;
            free(termo_ant);
        } else {
            termo->coef = termo->coef * termo->exp;
            (termo->exp)--;
            termo_ant = termo;
            termo = termo->prox;
        }
    }
    if (termo->exp == 0){
        termo_ant->prox = NULL;
    } else {
        termo->coef = termo->coef * termo->exp;
        (termo->exp)--;
    }
}


void imprimePolinomio(polinomio *pol)
{
    noPolinomio *termo = pol;
    if( termo->coef > 0 ){
        printf("+ %.2fx^%d ", termo->coef, termo->exp);
    } else {
        printf("- %.2fx^%d ", fabs(termo->coef), termo->exp);
    }
    termo = termo->prox;
    while(termo->prox != NULL){
        if( termo->coef > 0 ){
            printf("+ %.2fx^%d ", termo->coef, termo->exp);
        } else {
            printf("- %.2fx^%d ", fabs(termo->coef), termo->exp);
        }
        termo = termo->prox;
    }
    if( termo->coef > 0 ){
        printf("+ %.2fx^%d \n", termo->coef, termo->exp);
    } else {
        printf("- %.2fx^%d \n", fabs(termo->coef), termo->exp);
    }
}


void destroyPolinomio(polinomio *p)
{
    polinomio *q = p;
    while (p->prox != NULL )
    {
        q = p;
        p = p->prox;
        free(q);
    }
    free(p);
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
    derivaPolinomioa(&pol);
    imprimePolinomio(pol);

    destroyPolinomio(pol);
    return(0);
}