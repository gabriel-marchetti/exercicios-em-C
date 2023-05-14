#ifndef PILHA_DINAMICA_
#define PILHA_DINAMICA_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#ifndef bool
typedef int bool;
enum { false, true };
#endif

typedef struct _pilha{
    char ch;
    struct _pilha *next;
} pilha;

pilha *criaPilha();
void empilha( pilha **pil, char letra);
void desempilha( pilha **pil);
int calculaPilha( pilha *pil);
void destroiPilha(pilha **pil);

#endif