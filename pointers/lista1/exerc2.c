#include <stdio.h>
#include <stdlib.h>
#define LEN 40


void myStrCopy(char *destino, char *origem){
    for (int i = 0; i < LEN; i++){
        destino[i] = origem[i];
    }
}


int main(){
    /* Quero implementar a função string copy */
    char str1[LEN] = "Eu estou confuso", str2[LEN];

    myStrCopy(str2, str1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return(0);
}