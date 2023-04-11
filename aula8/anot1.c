#include <stdio.h>
#include <stdlib.h>

typedef struct pt
{
    float x;
    float y;
} ponto ;


void funcao(ponto *q)
{
    q -> x = 2; // (*q).x = 2;
    q -> y = 3; // (*q).y = 3;
}


int main()
{
    ponto P;

    funcao(&P);

    return(0);
}