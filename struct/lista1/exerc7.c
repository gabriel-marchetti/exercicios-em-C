#include <stdio.h>
#include <stdlib.h>

typedef struct _horario{
    int hora;
    int minuto;
    int segundo;
} horario;

typedef struct _data{
    int dia;
    int mes;
    int ano;
} data;

typedef struct _compromisso{
    char *data;
    char *hor;
    char *descr;
} _compromisso;

typedef struct _byte{
    char p1;
    char p2;
    char p3;
    char p4;
    char p5;
    char p6;
    char p7;
    char p8;
} byte;


void imprimeHorario(horario var)
{
    printf("%d horas %d minutos %d segundos\n", var.hora, var.minuto, var.segundo);
}


int main(void)
{
    FILE *file;
    file = fopen("exerc7.txt", "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return(-1);
    }

    

    return(0);
}