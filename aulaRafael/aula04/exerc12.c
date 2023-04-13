#include <stdio.h>


int myStrlen(char *name){
    int i;
    for (i = 0; name[i] != '\n'; i++);
    return(i);
}

int main(){
    char name[50];

    printf("Insira o nome: "); fgets(name, 50, stdin);
    printf("O tamanho da string eh: %d\n", myStrlen(name));

    return(0);
}