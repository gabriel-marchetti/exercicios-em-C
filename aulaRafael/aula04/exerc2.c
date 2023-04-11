#include <stdio.h>

int main(){
    int k;
    char plain, crypto;
    
    printf("Escolha um numero para a cifra\n");
    scanf("%d", &k);
    printf("Escolha uma letra para a cifra\n");
    setbuf(stdin, NULL);
    scanf("%c", &plain);

    while( plain != '#'){
        crypto = 'A' + (plain - 'A' + 26 + k) % 26;
        printf("%c\n", crypto);
        printf("Escolha uma outra letra para a cifra\n");
        setbuf(stdin, NULL);
        scanf(" %c", &plain);
    }

    return(0);
}