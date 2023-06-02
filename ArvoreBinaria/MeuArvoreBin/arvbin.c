#include "arvbin.h"

arvbin *CriaNode(int valor){
    arvbin *T = (arvbin *)calloc(1, sizeof(arvbin));
    T->info = valor;
    T->esq = NULL; T->dir = NULL;
    return T;
}

void InsereValor(arvbin **T, int insere)
{
    if ( (*T) == NULL ){
        (*T)    = CriaNode(insere);
    } else {
        if ( insere >= (*T)->info ){
            /* Insiro à direita. */
            InsereValor( &((*T)->dir), insere );
        } else {
            /* Insiro à esquerda. */
            InsereValor( &((*T)->esq), insere );
        }
    }
}

