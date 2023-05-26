#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct _arvbin{
    int info;
    struct _arvbin *esq, *dir;
} abb, noAbb;



int main( void )
{
    FILE *file;
    file = fopen("test.txt", "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    int n;
    fscanf(file, "%d ", &n);
    
    char stringSim[n*3], stringPos[n*3];
    fgets(stringSim, 3*n, file);
    fgets(stringPos, 3*n, file);

    int Sim[3*n], Pos[3*n];
    for (int i = 0; stringSim[i] != '\n' && stringSim[i] != '\0'; i++ ){
        if ( stringSim[i] != ' '){
            if ( stringSim[i] != '-'){
                
            }
        } 
        // Sim[i] = atoi(&stringPos[i * 2]);
    }
    for (int i = 0; stringPos[i] != '\n' && stringPos[i] != '\0'; i++){
        Pos[i] = atoi(&stringSim[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", Pos[i * 2]);
    } printf("\n");


    return 0;
}