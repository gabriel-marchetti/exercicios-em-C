#include <stdio.h>

int main(){
    char string;
    int i;
    
    string = "Gabriel";
    for(i = 0; string[i] != '\0'; i++);
    
    printf("Tamanho string: %d\n", i);

    return(0);
}