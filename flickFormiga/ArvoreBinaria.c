#include "ArvoreBinaria.h"
/*___________________AUXILIARES________________________*/
void hello()
{
    printf("Hello World\n");
}

void printArray(int *array, int tamanho)
{
    for(int i = 0; i  < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
/*******************************************************/

/*______________________FUNÇÔES BOAS___________________*/

arvbin *buildTree(int tamanho, int *sim, int *pos)
{
    /*-----CASO BASE------*/
    if ( tamanho <= 0 ){
        return NULL;
    }

    /*-----CASO ESTRANHO-----*/
    /*
    Criar Nó Raiz (X)
    Descobrir tamanhos simEsq = posEsq E simDir = posDir ()
    Preciso construir a simEsq, simDir ()
    Preciso construir a posEsq, posDir ()
    */

    /*Tamanho é o número de elementos, logo o último elemento do array pos é tamanho - 1*/
    int lastArray = tamanho - 1, root = pos[lastArray];
    arvbin *subtree = createNodeTree(root);
    /*Search Position of root in sim.*/
    /*Sps:
    SIM: 2 -1 4 5 -12 -2 2 3
    POS: 2 4 5 -1 2 -2 3 -12
    We want the index of -12 in SIM. So we can compute the length of simEsq and simDir.
    */
    int index;
    for(int i = 0; i < tamanho; i++){
        if( root = sim[i] ){
            index = i;
            break;
        }
    } // We have the index of -12 in SIM stored at index!
    // So how can i use it to compute the length of simEsq and simDir?

    return subtree;
}


arvbin *createNodeTree(int info)
{
    arvbin *T   = (arvbin *)calloc(1, sizeof(arvbin));
    T->info     = info;

    return T;
}


/*******************************************************/