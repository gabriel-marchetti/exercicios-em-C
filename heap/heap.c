#include <stdio.h>
#include <stdlib.h>


/*--Espaço das Funções--*/



/*---------------------*/


/* Função Main: Corpo Principal */
int main(int argc, char *argv[])
{
    /*---Variáveis---*/

    FILE *file=NULL;
    int condition, continuar=1;

    /*---------------*/

    while ( continuar )
    printf("----Operacoes----\n");
    printf("1 - Push no Heap.\n");
    printf("2 - \n");
    printf("99 - Parar \n");
        switch (condition){
        case 1:
            printf("processando...\n");
            break;
        case 99:
            continuar = 0;
        default:
            break;
        }


    return 0;
}