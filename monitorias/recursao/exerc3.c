#include <stdio.h>
#include <stdlib.h>


int fibo(int n){
    if (n < 2) {
        return(n);
    }
    return(fibo(n-1) + fibo(n-2));
}


int main(void) {
    int n, fibNumber;
    scanf("%d", &n);

    fibNumber = fibo(n);
    printf("o %d⁰ numero de Fibonacci eh: %d\n", n, fibNumber);

    return(0);
}