#include <stdio.h>
#include <stdlib.h>

#define L 100


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


int myStrcmp(char *str1, char *str2)
{
    while (*str1) {
        if (*str1 != *str2){
            return(0);
        }
        str1++;
        str2++;
    }
    return(1);
}


int main(void)
{
    char *str1 = calloc(L, sizeof(char));
    char *str2 = calloc(L, sizeof(char));

    // Para ler as strings estáticas e passar para dinâmicas:
    char input1[L], input2[L]; 

    printf("Digite a primeira string: "); scanf("%s", input1);
    printf("Digite a segunda string: "); scanf("%s", input2);

    myStrCopy(str1, input1);
    myStrCopy(str2, input2);
    // Estou com os vetores dinâmicos! 
    
    int cond;
    cond = myStrcmp(str1, str2);
    if (cond){
        printf("As strings são iguais\n");
    } else {
        printf("As strings são diferentes\n");
    }

    return(0);
}