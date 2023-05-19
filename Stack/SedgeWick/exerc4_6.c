#include "stack.h"
#define MAX 100

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
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
        if ( string[i] = '*'){
            STACKpop(&Q, &lenght);
        } else if (string[i] = ' '){
            continue;
        } else {
            STACKpush(&Q, string[i], &lenght);
        }
    }


    return(0);
}