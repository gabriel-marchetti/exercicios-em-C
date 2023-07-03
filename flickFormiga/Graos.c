#include "ArvoreBinaria.h"

int main(int argc, char *argv[])
{
    /*==========OpenFILE===========*/
    FILE *fp;
    fp = fopen(argv[1], "r");
    argv[1] = "input01.txt";
    if ( fp == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }
    /*++++++++++++++++++++++++++++*/

    int tamanho;
    fscanf(fp, "%d\n", &tamanho);
    int *sim = (int *)malloc(tamanho*sizeof(int));
    int *pos = (int *)malloc(tamanho*sizeof(int));

    /*--Salva-Sim--*/
    for(int i = 0; i < tamanho; i++){
        fscanf(fp, "%d", &sim[i]);
    }
    // printArray(sim, tamanho);
    /*--Salva-Pos--*/
    for(int i = 0; i < tamanho; i++){
        fscanf(fp, "%d", &pos[i]);
    }
    // printArray(pos, tamanho);

    // Fecho Arquivo.
    fclose(fp);

    /*****************************/
    /*COMEÇO AS COISAS LEGAIS*/
    arvbin *tree = NULL;
    tree = buildTree(tamanho, sim, pos);
    printBinaryTree(tree, 0);

    free(sim); free(pos);
    return 0;
}