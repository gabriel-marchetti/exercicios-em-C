#include <stdio.h>

int main(){
    char name[50], lastName[100];

    printf("Introduza o seu nome: "); scanf("%s", name);
    printf("Introduza o seu sobrenome: "); scanf("%s", lastName);

    printf("Nome Completo: %s %s\n", name, lastName);

    return(0);
}