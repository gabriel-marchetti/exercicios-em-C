#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void sortAgenda(Agenda **lista, int n)
{
    Agenda aux;
    int posAux;
    for(int i = 0; i < n; i++){
        aux = (*lista)[i];
        posAux = i;
        for(int j = i; j < n; j++){
            if( strcmp(aux.nome, ((*lista)[j]).nome) > 0 ){
                aux = (*lista)[j];
                posAux = j;
            }
        }
        (*lista)[posAux] = (*lista)[i];
        (*lista)[i] = aux;
    }
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc1.txt", "r");
    int n;
    fscanf(fp, "%d ", &n);

    Agenda *lista = criaAgenda(n);
    char nomeAux[M], endAux[M], telAux[M];
    for (int i = 0; i < n; i++){
        fgets(lista[i].nome, M, fp);
        fgets(lista[i].ender, M, fp);
        fgets(lista[i].tel, M, fp);
    }
    
    sortAgenda(&lista, n);
    for (int i = 0; i < n; i++){
        printf("-------------------------------\n");
        printf("Nome: %s", lista[i].nome);
        printf("Endereco: %s", lista[i].ender);
        printf("Telefone: %s", lista[i].tel);
    }
    printf("-------------------------------\n");
    
    free(lista);
    return(0);
}