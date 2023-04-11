#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERRO 1e-10

double myAbs(double a, double b){
    if ( a > b ){
        return(a-b);
    } else {
        return(b-a);
    }
}

double metBab(double valor){
    double yn = valor, yna;
    while ( myAbs(yn, yna) >  ERRO )
    {
        yna = yn;
        yn = (yn + valor/yn)/2;
    }
    return(yn);
}

int main(){
    double valor;
    printf("Digite o valor da raiz: ");
    scanf("%lf", &valor);

    valor = metBab(valor);
    printf("A raiz eh: %f\n", valor);

    return(0);
}