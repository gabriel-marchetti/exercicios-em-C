#include "stack.h"
#define MAX 100

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen("test1.txt", "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return(-1);
    }

    stack *Q;
    char save, string[MAX];

    int lenght = 0;
    while(!feof(file)){
        fgets(string, MAX, file);
        //printf("%s", string);
    }

    for ( int i = 0; string[i] != '\0' && string[i] != '\n'; i++){
        if ( string[i] == '*'){
            // printf("Processo A\n");
            save = STACKpop(&Q, &lenght);
            printf("*  %c \t", save); STACKprint(Q);
        } else if (string[i] == ' '){
            continue;
        } else {
            // printf("Processo B\n");
            printf("%c \t", string[i]);
            STACKpush(&Q, string[i], &lenght);
            STACKprint(Q);
            printf("\n");
        }
    }


    return(0);
}