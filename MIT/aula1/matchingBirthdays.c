#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct _BirthDays{
    char name[MAX];
    char mounth[3];
    int day;
    int year;
    struct _BirthDays *next;
} birthday;

birthday *criaRegistro(char name[MAX], int day, int year, char month[3]);
void addRegistro(birthday **Registro, char name[MAX], int day, int year, char mounth[3]);
int buscaMatch(birthday *Registro, int day, int year, char mounth[3]);


int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    birthday *Registro = NULL;
    char nameAux[MAX], mounthAux[3];
    int dayAux, yearAux, cond = 1;
    while ( fgets(nameAux, sizeof(nameAux), file) != NULL &&
            fscanf(file, "%d-%s-%d", &dayAux, mounthAux, &yearAux) == 3 ){
        nameAux[strcspn(nameAux, "\n")] = '\0';

        if (buscaMatch(Registro, dayAux, yearAux, mounthAux)){
            printf("Matching pair.\n");
            cond = 0;
            break;
        } else {
            addRegistro(&Registro, nameAux, dayAux, yearAux, mounthAux);
        }
    }
    if (cond) printf("No matching pairs.\n");    

    return 0;
}


birthday *criaRegistro(char name[MAX], int day, int year, char month[3])
{
    birthday *p = (birthday *)calloc(1, sizeof(birthday));
    strcpy(p->name, name);
    strcpy(p->mounth, month);
    p->day  = day;
    p->year = year;
    return(p);
}


void addRegistro(birthday **Registro, char name[MAX], int day, int year, char mounth[3])
{
    birthday *p = (birthday *)calloc(1, sizeof(birthday)), *aux = *Registro;
    if ( *Registro == NULL ){
        *Registro = criaRegistro(name, day, year, mounth);
    } else {
        strcpy(p->name, name);
        strcpy(p->mounth, mounth);
        p->day  = day;
        p->year = year;
        while ( aux->next != NULL ) 
            aux = aux->next;
        aux->next = p;
    }
}


int buscaMatch(birthday *Registro, int day, int year, char mounth[3])
{
    if ( Registro == NULL ){
        return(0);
    } else {
        if ( Registro->year == year && Registro->day == day && strcmp(Registro->mounth, mounth) == 0){
            return(1);
        } else {
            return buscaMatch(Registro->next, day, year, mounth);
        }
    }
}