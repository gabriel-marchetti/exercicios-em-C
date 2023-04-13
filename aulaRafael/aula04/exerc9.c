#include <stdio.h>

int main(){
    /*  Nesse caso estamos usando a função fgets(), nela colocamos a variavel
    em que a string deve ser armazenada. Além disso, precisamos providenciar
    o tamanho máximo da string e a entrada do arquivo, nesse caso estamos
    usando a stdin!*/
    char name[100];
    printf("Insira o seu nome completo: "); 
    fgets(name, 100, stdin);
    printf("O seu nome eh: %s", name);

    return(0);
}