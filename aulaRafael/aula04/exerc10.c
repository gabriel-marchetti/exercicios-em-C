#include <stdio.h>

int main(){
    char names[100];

    while (1)
    {
        printf("Adicione um nome: "); 
        fgets(names, 100, stdin);
        if (names[0] == '\n'){
            break;
        } else {
            printf("O nome adicionado: %s", names);
        }
    }

    return(0);
}