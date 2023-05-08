#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _polinomio {
    float coef;
    int exp;
    struct _polinomio *prox;
} polinomio, noPolinomio;

typedef enum _bool{
    false,
    true,
} Bool;


polinomio *criaPolinomio()
{
    noPolinomio *termo = (noPolinomio *)calloc(1, sizeof(polinomio));
    return termo;
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
        printf("+ %.2fx^%d\n", termo->coef, termo->exp);
    } else {
        printf("- %.2fx^%d\n", fabs(termo->coef), termo->exp);
    }
}


Bool expoenteNoPolinomio( polinomio *p, int exp )
{
    polinomio *termo = p;
    while (termo->prox != NULL) {
        if(termo->exp == exp){
            return(true);
        } else {
            termo = termo->prox;
        }
    }
    if (termo->exp == exp){
        return(true);
    } else {
        return(false);
    }
}


void substituiCoef(polinomio **p ,int exp, float coef)
{
    polinomio *termo = *p;
    if((*p)->exp == exp){
        (*p)->coef = coef;
    } else {
        while( termo->prox != NULL ){
            if( termo->exp == exp ){
                termo->coef = coef;
                return;
            }
            termo = termo->prox;
        }
        if ( termo->exp == exp ){
            termo->coef = coef;
            return;
        }
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

    int n, *tamanho;
    tamanho = (int *)malloc(sizeof(int));
    fscanf(fp, "%d", &n);
    *tamanho = n;
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

    printf("O polinômio do .txt foi criado!\n");
    int continua = 1, cond;
    char op;
    while (continua){
        printf("Se deseja adicionar um novo elemento digite 1.\n");
        printf("Se deseja saber o tamanho do polinômio digite 2.\n");
        scanf("%d", &cond);
        switch (cond){
        case 1:
            printf("Digite o coeficiente e o expoente separados por um espaço.\n");
            scanf("%f %d", &auxCoef, &auxExp);
            if ( expoenteNoPolinomio(pol, auxExp) ){
                printf("Esse expoente já tem coeficiente.\n"); 
                printf("Deseja substituir(S ou N): "); 
                setbuf(stdin, NULL);
                scanf("%c", &op);
                if( op == 'S' ){
                    substituiCoef(&pol ,auxExp, auxCoef); 
                    printf("Coeficiente substituido.\n");
                } else {
                    printf("Operação cancelada.\n");
                    continue;
                }
            } else {
                printf("Inserindo Monomio no polinomio...\n");
                inserePolinomioHierarquico(&pol, auxCoef, auxExp);
                (*tamanho)++; 
                printf("Elemento inserido com sucesso.\n");
            }
            break;
        case 2:
            printf("Tamanho do polinômio: %d\n", *tamanho);
            break;
        default:
            continua = 0;
            break;
        }
    }

    destroyPolinomio(pol);
    free(tamanho);
    return(0);
}