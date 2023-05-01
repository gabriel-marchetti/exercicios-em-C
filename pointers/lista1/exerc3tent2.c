#include <stdio.h>
#include <stdlib.h>

#define TAM 40


void myStrCopy(char *destiny, char *origin)
{
    while (*origin){
        *destiny = *origin;
        destiny++;
        origin++;
    }
    destiny++;
    *destiny = '\0';
}


int main(void)
{
    char *str1 = calloc(TAM, sizeof(char));
    char *str2 = calloc(TAM, sizeof(char));

    if ( str1 == NULL || str2 == NULL ){
        printf("Sem memória suficiente\n");
        return(-1);
    }

    myStrCopy(str1, "Eu estou confuso");
    myStrCopy(str2, str1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    free(str1); free(str2);

    return(0);
}