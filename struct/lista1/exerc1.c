#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct _agenda{
    char nome[M];
    char ender[M];
    char tel[M];
} Agenda;


Agenda *criaAgenda(int size)
{
    Agenda *p = (Agenda *)calloc(size, sizeof(Agenda));
    return p;
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc1.txt", "r");
    int n;
    fscanf(fp, "%d", &n);

    Agenda *lista = criaAgenda(n);
    char nomeAux[M], endAux[M], telAux[M];
    for (int i = 0; i < n; i++){
        fscanf(fp, "%s", nomeAux);
        fscanf(fp, "%s", endAux);
        fscanf(fp, "%s", telAux);
        /* Tenho que fazer o esquema de duplicar string. */
    }
    
    free(lista);
    return(0);
}