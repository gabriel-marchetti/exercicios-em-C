#include "FilaPrioridade.h"

/*------------MAIN--------------*/
int main( int argc, char *argv[] )
{
    FILE *file;
    argv[1] = "teste1.txt";
    file = fopen(argv[1], "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    char action, *name=NULL;
    int priority, n;
    fscanf(file, "%d ", &n);
    printf("%d\n", n);
    for ( int i = 0; i < n; i++ ){
        fscanf(file, "%c ", &action);
        printf("%c", action);
        // printf("%c\n", action);
        switch (action){
            case 'I':
                fscanf(file, "%s %d\n", name, &priority);
                printf("%s %d", name, priority);
                printf("\n");
                break;
            case 'P':
                break;
            case 'L':
                break;
            case 'D':
                break;
            case 'M':
                break;
            case ' ':
                break;
            default:
                printf("I don't have this option!\n");
                break;
       }
    }
}