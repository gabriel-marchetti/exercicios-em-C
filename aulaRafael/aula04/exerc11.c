#include <stdio.h>


int myStrlen(char *str){
    int i = 0;
    while (str[i] != '\n' )
    {
        i++;
    }
    return(i);
}

int main(){
    char name[30];

    printf("Insira o nome: "); 
    fgets(name, 30, stdin);

    printf("O comprimento da string eh: %d\n", myStrlen(name));

    return(0);
}