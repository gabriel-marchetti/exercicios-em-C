#include <stdio.h>
#include <stdlib.h>

typedef struct _ArvBin{
    int info;
    struct _ArvBin *esq, *dir;
} arvbin, nodeArvbin;


int main(int argc, char *argv[])
{
    /* Lendo as entradas do arquivo. */
    FILE *file;
    file = fopen(argv[1], "r");
    if ( file == NULL )
    { printf("Could't find the file.\n"); return -1;}


    int n;
    fscanf(file, "%d", &n); // no principal trocar por scanf.

    int Sim[n], Pos[n];
    for (int i = 0; i < n; i++){
        fscanf(file, "%d", &Sim[i]); // no principal trocar por scanf.
    }
    for (int i = 0; i < n; i++){
        fscanf(file, "%d", &Pos[i]); // no principal trocar por scanf.
    }

    /* Terminando de ler as entradas. */

    /* Printando as entradas do arquivo. */
    /*
    printf("Pos: ");
    for (int i = 0; i < n; i++){
        printf("%d ", Pos[i]);
    }   printf("\n");

    printf("Sim: ");
    for (int i = 0; i < n; i++){
        printf("%d ", Sim[i]);
    }   printf("\n");
    */
    /* Terminando de printar as entradas do arquivo. */
    

    return 0;
}



