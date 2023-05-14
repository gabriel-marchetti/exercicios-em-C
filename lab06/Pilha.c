#include "Pilha.h"

pilha *criaPilha()
{
    pilha *p = (pilha *)calloc(1, sizeof(pilha));
    return(p);
}

void empilha(pilha *pil, char letra)
{
    pilha *ad;
    if ( pil == NULL ){
        pil = criaPilha();
    } else {
        ad = (pilha *)calloc(1, sizeof(pilha));
        ad->ch = letra;
        ad->next = pil;
        pil = ad;
    }
}

void desempilha(pilha *pil)
{
    pilha *ad = NULL;
    if ( pil == NULL ){
        return;
    } else if ( pil->next == NULL ){
        free(pil);
    } else {
        ad = pil;
        pil = pil->next;
        free(ad);
    }
}

int calculaPilha(pilha *pil)
{
    int retorno = 0;
    while(pil->next != NULL){
        retorno = retorno + (int)pil->ch;
        pil = pil->next;
    }
    retorno = retorno + (int)pil->ch;
}

void destroiPilha(pilha **pil)
{
    pilha *ad = NULL;
    while ((*pil)->next != NULL){
        ad = *pil;
        *pil = (*pil)->next;
        free(ad);
    }
    free(pil);
}
