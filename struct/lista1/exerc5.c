#define M 100
#include <stdio.h>
#include <stdlib.h>

typedef struct _aluno{
    char nome[M];
    int numMat;
    char curso[M];
} aluno;


void imprimeSala(aluno Classe[], int tam)
{
    for( int i = 0; i < tam; i++){
        printf("-----------------\n");
        printf("Nome: %s", Classe[i].nome);
        printf("RA: %d\n", Classe[i].numMat);
        printf("Curso: %s", Classe[i].curso);
    }
    printf("----------------\n");
}


void insertingSort(aluno Classe[], int tam)
{
    int aux;
    aluno guard;
    for (int i = 0; i < tam; i++){
        aux = i;
        guard = Classe[i];
        for(int j = i; j < tam; j++){
            if( Classe[j].numMat < Classe[aux].numMat ){
                aux = j;
                guard = Classe[j];
            }
        }
        Classe[aux] = Classe[i];
        Classe[i] = guard;
    }
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc5.txt", "r");

    aluno Classe[5];
    for (int i = 0; i < 5; i++){
        fgets(Classe[i].nome, M, fp);
        fscanf(fp, "%d ", &(Classe[i].numMat));
        fgets(Classe[i].curso, M, fp);
    }

    imprimeSala(Classe, 5);
    insertingSort(Classe, 5);
    printf("\n");
    imprimeSala(Classe, 5);

    return(0);
}