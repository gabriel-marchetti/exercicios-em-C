#include <stdio.h>
#include <stdlib.h>


void iimprimeNum(int n){
    if (n == 20){
        printf("%d\n", n);
        return;
    }
    printf("%d ", n);
    iimprimeNum(n+1);
}


void imprimeNum(int n){
    if (n == 1){
        printf("%d ", n);
        return;
    }
    imprimeNum(n-1);
    printf("%d ", n);
}

/* Quero um problema que conte até o número n recursivamente. */
int main(void){
    int n;
    scanf("%d", &n);
    imprimeNum(n-1);
    printf("%d\n", n);

    return(0);
}