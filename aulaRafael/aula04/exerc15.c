#include <stdio.h>
#include <stdlib.h>
#define TAM 50


char *createVector(int n){
    char *vector = (char *)calloc(n, sizeof(char));
    return(vector);
}


void destroyVector(char **vector){
    if (*vector != NULL){
        free(*vector);
        *vector = NULL;
    }
}


int myStrlen(char *string){
    int i;
    for(i = 0; string[i] == '\n' || string[i] == '\0'; i++);
    return(i);
}


void removeSpecial(char *str){
    for (int i = 0; i < myStrlen(str); i++){
        if (str[i] == '\n'){
            str[i] == '\0';
            break;
        }
    }
}

char *strcat(char *dest, char *orig){
    int tamDest, tamOrig;
    tamDest = myStrlen(dest);
    tamOrig = myStrlen(orig);

    for (int i = 0; i < tamOrig; i++){
        dest[i+tamDest] = orig[i];
    }
}


int main(){
    char *quote1, *quote2;
    quote1 = (char *)calloc(TAM, sizeof(char)); quote2 = (char *)calloc(TAM, sizeof(char));
    printf("Adicione a primeira string: "); fgets(quote1, TAM, stdin);
    printf("Adicione a segunda string: "); fgets(quote2, TAM, stdin);
    removeSpecial(quote1); removeSpecial(quote2);

    quote1 = strcat(quote1, quote2);
    printf("%s\n", quote1);

    destroyVector(&quote1); destroyVector(&quote2);
    return(0);
}