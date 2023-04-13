#include <stdio.h>


typedef enum{
    false,
    true,
} bool;


bool isNull(char *str){
    if (str[0] == '\0' || str[0] == '\n')
    {
        return(true);
    } else {
        return(false);
    }
}


void terminalPrint(bool state){
    if (state == false){
        printf("Falso!\n");
    } else {
        printf("Verdadeiro!\n");
    }
}

int main(){
    char str[50];
    printf("Insira uma palavra: "); fgets(str, 50, stdin);
    terminalPrint(isNull(str));
    terminalPrint(isNull(""));

    return(0);
}