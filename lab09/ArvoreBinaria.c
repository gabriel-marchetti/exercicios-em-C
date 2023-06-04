#include "ArvoreBinaria.h"

void createTree(arvbin **T)
{
    if ( T == NULL ){
        *T = (arvbin *)calloc(1, sizeof(arvbin));
    }
}

arvbin *createNode(int info)
{
    arvbin *p = (arvbin *)calloc(1, sizeof(arvbin));
    p->info = info;
    return p;
}

void insertNode(arvbin **T, int info)
{
    nodeArvbin *p = createNode(info);
    if ( *T == NULL ){
        (*T) = p;
    } else {
        /* Percorre Árvore. */
        if ( (*T)->info < info ){
            insertNode( &((*T)->dir) , info);
        } else {
            insertNode( &((*T)->esq), info);
        }
    }
}

arvbin *createTreeSimPos(int *sim, int *pos, int n)
{
    if ( n <= 0 ){
        return NULL;
    }

    int position = n-1;
    int elem = pos[position];
    nodeArvbin *p = createNode(elem);
    /* Já usei a posição para achar o último da pós-Ordem, então vou usar essa mesma var.*/
    position = searchPos(sim, n, elem);
    /* Agora preciso dividir a sim e a pos para a próxima iteração. */
    int sim1[position], sim2[n - position - 1]; //modifiquei aqui
    int pos1[position], pos2[n - position - 1];
    // Vamos pensar na seguinte árvore.
    // Sim = [4, 8, 2, 5, 1, 6, 3, 7]
    // Pos = [8, 4, 5, 2, 6, 7, 3, 1]
    // Queremos:
    // sim1 = [4, 8, 2, 5] pos1 = [8, 4, 5, 2]
    // sim2 = [6, 3, 7] pos2 = [6, 7, 3]
    for( int i = 0; i < position; i++){ // modifiquei aqui
        sim1[i] = sim[i];
        pos1[i] = pos[i];
    }
    // Consegui sim1 e pos1
    for( int i = 0 ; i < n - position - 1; i++){
        sim2[i] = sim[position + i +1];
        pos2[i] = pos[position + i];
    }
    p->esq = createTreeSimPos(sim1, pos1, position );
    p->dir = createTreeSimPos(sim2, pos2, n - position - 1);
    
    return p;
}

int searchPos(int *array, int n, int wanted)
{
    for (int i = 0 ; i < n ; i++){
        if ( array[i] == wanted) return(i);
    }
    return 0;
}

void printBinaryTree(arvbin *T, int h)
{
    if ( T != NULL ){
        printBinaryTree(T->dir, h+1);
        for(int i=0; i < h; i++) printf("   ");
        printf("%d", T->info);
        printf("\n");
        printBinaryTree(T->esq, h+1);
    }
}

void preOrder(arvbin *T)
{
    if ( T != NULL ){
        printf("%d ", T->info);
        preOrder(T->esq);
        preOrder(T->dir);
    }
}

void inOrder(arvbin *T)
{
    if ( T != NULL ){
        inOrder(T->esq);
        printf("%d ", T->info);
        inOrder(T->dir);
    }
}

void posOrder(arvbin *T)
{
    if ( T != NULL ){
        posOrder(T->esq);
        posOrder(T->dir);
        printf("%d ", T->info);
    }
}

arvbin *invertTree( arvbin *T )
{
    /* Se entrar num nó null ele continua null .*/
    if ( T == NULL) return NULL;
    nodeArvbin *p = createNode(T->info);
    /* Senão ele inverte as entradas. */
    p->dir = invertTree(T->esq);
    p->esq = invertTree(T->dir);
    return p;
}

void destroyTree( arvbin **T )
{
    if ( (*T) == NULL ) return;
    destroyTree(&((*T)->esq));
    destroyTree(&((*T)->dir));
    free(*T);
}

void internalPathLength( arvbin *T, int peso, int *IPL )
{
    if ( T == NULL ) return;
    *IPL = *IPL + peso;
    internalPathLength( T->esq,  peso + 1, IPL);
    internalPathLength( T->dir, peso + 1, IPL);
}