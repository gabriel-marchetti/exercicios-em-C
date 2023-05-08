#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef enum _bool {
    false,
    true,
} bool;

void reverseString( char string[M], char revString[M], int n, int * nAux )
{
    if (string[n] != '\0' && string[n] != '\n'){
        reverseString(string, revString, n+1, nAux);
        revString[*nAux] = string[n];
        (*nAux)++;
    }
    if ( n == 0 ){
        revString[(*nAux)++] = '\0';
    }
}


int lengthStr( char string[M] )
{
    int i;
    for ( i = 0; string[i] != '\0' && string[i] != '\n'; i++);
    return(i);
}


bool checkPalindrome(char string[M], char revStr[M], int tamanho )
{
    for( int i = 0; i < tamanho; i++){
        if(string[i] != revStr[i]){
            return(false);
        }
    }
    return(true);
}


char *converteString( char string[M] ){
    int i = 0, j = 0;
    char returnString[M];
    while ( string[i] != '\0' ){
        if ( string[i] == '\n'){
            string[j] = string[i];
        } else if ((int)string[i] >= 65 && (int)string[i] <= 90){
            (int)string[i]
        }
    }
}


int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("palindrome.txt", "r");

    if ( fp == NULL ){
        printf("Arquivo não encontrado.\n");
        return(-1);
    }

    char string[M], revString[M];
    int n = 0, nAux = 0;
    fgets(string, M, fp);
    printf("String read:\t %s", string);
    reverseString(string, revString, n, &nAux);
    printf("Reverse string:\t %s\n", revString);
    int tamanhoOr, tamanhoRev;
    tamanhoOr = lengthStr(string);
    tamanhoRev = lengthStr(revString);
    printf("tamanho original: %d \t tamanho Reverso: %d\n", tamanhoOr, tamanhoRev);

    if (checkPalindrome(string, revString, tamanhoOr) ){
        printf("A palavra é palindromo.\n");
    } else {
        printf("A palavra não é palindromo.\n");
    }

    return(0);
}