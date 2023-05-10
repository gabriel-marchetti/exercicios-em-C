#define M 100
#include <stdio.h>
#include <stdlib.h>

typedef struct _registro{
    char name[M];
    int age;
    char sex;
    char cpf[M];
    char born[M];
    int sector;
    char job[M];
    float salary;
} registro;


void imprimeEmpresa(registro *empresa, int n)
{
    for( int i = 0; i < n; i++){
        printf("----------\n");
        printf("Nome: %s", empresa[i].name);
        printf("Idade: %d\n", empresa[i].age);
        printf("Sex: %c\n", empresa[i].sex);
        printf("CPF: %s", empresa[i].cpf);
        printf("Born: %s", empresa[i].born);
        printf("Cargo: %s", empresa[i].job);
        printf("Setor: %d\n", empresa[i].sector);
        printf("Salary: %f\n", empresa[i].salary);
    }
    printf("-----------\n");
}


int main(void)
{
    FILE *file;
    file = fopen("exerc8.txt", "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return(-1);
    }

    int tamanho;
    fscanf(file, "%d ", &tamanho);
    registro *empresa = (registro *)calloc(tamanho, sizeof(registro));

    int i = 0;
    for (int i = 0; i < tamanho; i++){
        fgets(empresa[i].name, M, file);
        fscanf(file, "%d ", &empresa[i].age);
        fscanf(file, "%c ",&empresa[i].sex);
        fgets(empresa[i].cpf, M, file);
        fgets(empresa[i].born, M, file);
        fgets(empresa[i].job, M, file);
        fscanf(file, "%d ", &empresa[i].sector);
        fscanf(file, "%f ",&empresa[i].salary);
    }
    imprimeEmpresa(empresa, tamanho);


    free(empresa);
    return(0);
}