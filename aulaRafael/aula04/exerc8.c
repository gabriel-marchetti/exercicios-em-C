#include <stdio.h>

int main(){
    /*  Notemos algumas coisas interessantes desse código, primeiro
        temos que no scanf notemos que não precisamos do caractere &
        uma vez que estamos passando como argumento um vetor de caracteres.
        Assim como, notemos que o scanf lê apenas o primeiro nome.*/
    char name[100];
    printf("Insira o seu nome: "); scanf("%s", name);
    printf("O seu nome eh: %s\n", name);

    return(0);
}