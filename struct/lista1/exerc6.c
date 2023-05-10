#define M 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _bool{
    false,
    true,
} bool;

typedef struct _aluno{
    int mat;
    char nome[M];
    float p1;
    float p2;
    float p3;
} aluno;


void sortAlunos(aluno Classe[M], int tamanho)
{
    int aux; aluno salt;
    for(int i = 0; i < tamanho; i++){
        aux = i;
        salt = Classe[i];
        for(int j = i; j < tamanho; j++){
            if ( Classe[j].mat < salt.mat ){
                aux = j;
                salt = Classe[j];
            }
        }
        Classe[aux] = Classe[i];
        Classe[i] = salt;
    }
}


void imprimeSala(aluno Classe[M], int tamanho)
{
    for (int i = 0; i < tamanho; i++){
        printf("-------------\n");
        printf("Matricula: %d\n", Classe[i].mat);
        printf("Nome: %s", Classe[i].nome);
        printf("Nota p1: %.2f\n", Classe[i].p1);
        printf("Nota p2: %.2f\n", Classe[i].p2);
        printf("Nota p3: %.2f\n", Classe[i].p3);
    }
    printf("-------------\n");
}


int indexMaiorNotaP1(aluno Classe[M], int tamanho)
{
    int aux = 0;
    float p1_maior = Classe[0].p1;
    for (int i = 1; i < tamanho; i++){
        if (p1_maior < Classe[i].p1 ){
            p1_maior = Classe[i].p1;
            aux = i;
        }
    }
    return(aux);
}


float *calculaMedias(aluno Classe[M], int tamanho)
{
    float *p = (float *)calloc(tamanho, sizeof(float));
    for (int i = 0; i < tamanho; i++){
        p[i] = (Classe[i].p1 + Classe[i].p2 + Classe[i].p3)/3;
    }
    return(p);
}


int indexMaiorMedia(float *notas, int tamanho, float *media){
    int index = 0;
    *media = notas[0];
    for (int i = 0; i < tamanho; i++){
        if ( *media < notas[i] ){
            *media = notas[i];
            index = i;
        }
    }
    return(index);
}


int indexMenorMedia(float *notas, int tamanho, float *media)
{
    int index = 0;
    *media = notas[0];
    for(int i = 0; i < tamanho; i++){
        if( *media > notas[i] ){
            *media = notas[i];
            index = i;
        }
    }
    return(index);
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc6.txt", "r");
    if ( fp == NULL ){
        printf("File not found.\n");
        return(-1);
    }

    aluno *classe = (aluno *)calloc(5, sizeof(aluno));
    
    for (int i = 0; i < 5; i++){
        fscanf(fp, "%d ", &(classe[i].mat));
        fgets(classe[i].nome, M, fp);
        fscanf(fp, "%f ", &(classe[i].p1));
        fscanf(fp, "%f ", &(classe[i].p2));
        fscanf(fp, "%f", &(classe[i].p3));
    }
    

    sortAlunos(classe, 5);

    bool cond = true;
    int sw, index;
    float *medias, media;
    medias = calculaMedias(classe, 5);
    while ( cond ){
        printf("Opcoes:\n");
        printf("1: Encontra aluno com maior nota na primeira prova.\n");
        printf("2: Encontra aluno com maior media geral.\n");
        printf("3: Encontra aluno com menor media geral.\n"); 
        printf("4: Da uma lista com o nome e a condicao do aluno.\n");
        printf("5: imprime informacoes dos alunos.\n");
        scanf("%d", &sw);
        switch(sw){
            case 1:
                index = indexMaiorNotaP1(classe, 5);
                printf("Aluno com maior nota na p1: %s", classe[index].nome);
                break;
            case 2:
                index = indexMaiorMedia(medias, 5, &media);
                printf("Aluno com maior media: %s", classe[index].nome);
                printf("Sua media foi: %.2f\n", media);
                break;
            case 3:
                index = indexMenorMedia(medias, 5, &media);
                printf("Aluno com menor media: %s", classe[index].nome);
                printf("Sua media foi: %.2f\n", media);
                break;
            case 4:
                break;
            case 5:
                imprimeSala(classe, 5);
                break;
            default:
                cond = false;
                break;
        }
    }

    free(classe);
    return(0);
}