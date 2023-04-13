#include <stdio.h>
#include <stdlib.h>
#define TAM 50


int myStrlen(char *str){
    int i;
    for (int i = 0; str[i] == '\0' || str[i] == '\n'; i++);
    return(i);
}



char *createVector(int n){
    char *vector = (char *)calloc(n, sizeof(char));
    return(vector);
}


void destroyVector(char **vector){
    if( *vector != NULL){
        free(*vector);
        *vector = NULL;
    }
}



char *myStrcopy(char *str, char *hack){
    int i;
    for (i = 0; i < myStrlen(str); i++)
    {
        hack[i] = str[i];
    }
    hack[i] = '\0';
    return(hack);
}

int main(){
    char *name, *copyName;
    name = createVector(TAM); copyName = createVector(TAM);

    printf("Insira o seu nome: "); fgets(name, TAM, stdin);
    copyName = myStrcopy(name, copyName);
    printf("%s", copyName);

    destroyVector(&name); destroyVector(&copyName);
    return(0);
}