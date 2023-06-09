#include "ArvoreBinaria.h"
#include "ArvoreBinaria.c"

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    /* Modificar para o Scanf no arquivo final. */
    int n;
    fscanf(file, "%d", &n);
    int sim[n], pos[n];
    for(int i = 0; i < n; i++) fscanf(file, "%d", &sim[i]);
    fflush(stdin);
    for(int i = 0; i < n; i++) fscanf(file, "%d", &pos[i]);
    
    // for(int i = 0; i < n; i++){ printf("%d ", sim[i]); printf("%d\n", pos[i]);}

    // Corpo do código.
    arvbin *T = NULL;
    T = createTreeSimPos(sim, pos, n);
    // printBinaryTree(T, 0);
    // Preciso teste esse código
    /* Preciso ver ser funciona com mais árvores! --> deu certo!!!*/
    /* Para isso devo fazer vários testes, ajudaria fazer um arquivo e testar as árvores na mão.*/
    arvbin *T2 = invertTree(T);
    preOrder(T2);   printf("\n");
    inOrder(T2);    printf("\n");
    posOrder(T2);   printf("\n");
    
    destroyTree(&T); destroyTree(&T2); 
    return 0;
}