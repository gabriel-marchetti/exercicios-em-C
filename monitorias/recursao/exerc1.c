#include <stdio.h>
#include <stdlib.h>



int fib(int n){
    if((n == 1) || (n == 2)){
        return(1);
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}


int main(){
    /* Problema: muitas computações desnecessárias. */
    int n, nfib;
    scanf("%d", &n);
    nfib = fib(n);
    printf("Fib %d: %d\n", n, nfib);
    return(0);
}