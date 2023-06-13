#include <stdio.h>
#include <stdlib.h>


/*--Estruturas-de-dados--*/


/*-----------------------*/


/*--Espaço das Funções--*/
void heapify()
{

}

/*---------------------*/


/* Função Main: Corpo Principal */
int main(int argc, char *argv[])
{
    /*---Variáveis---*/

    FILE *file=NULL;
    int condition, continuar=1;

    /*---------------*/

    while ( continuar ){
        // Options // 
        printf("----Operacoes----\n");
        printf("1 - Push no Heap.\n");
        printf("2 - Pop no Heap.\n");
        printf("3 - Peek no Heap.\n");
        printf("4 - Delete-max no Heap.\n");
        printf("5 - Heapify.\n");
        printf("6 - Merge no Heap.\n");
        printf("7 - Meld no Heap. \n");
        printf("8 - Size do Heap. \n");
        printf("9 - IsEmpty do Heap. \n"); 
        printf("99 - Parar \n");

        // Switch //
        fflush(stdin);
        scanf("Qual opcao quer realizar: %d", &condition);
        
        switch (condition){
        case 1:
            printf("processando...\n");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 99:
            continuar = 0;
            break;
        default:
            printf("Nao tenho essa opcao.\n");
            break;
        }
    }
    return 0;
}