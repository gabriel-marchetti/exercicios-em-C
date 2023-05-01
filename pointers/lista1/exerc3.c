#include <stdio.h>
#include <stdlib.h>

#define len 40


void myStrCopy(char *destiny, char *origin){
    int i;
    for (i = 0; origin[i] != '\0'; i++){
        destiny[i] = origin[i];
    }
    destiny[i] = '\0';
}


int main(){
    char *str1 = calloc(len, sizeof(char));
    char *str2 = calloc(len, sizeof(char));

    str1 = "Eu estou confuso";

    myStrCopy(str2, str1);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    free(str1); free(str2);
    return(0);
}