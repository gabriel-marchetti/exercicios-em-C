#include "arvbin.h"

void ImprimeMenu()
{
  printf("\n-------Digite--------\n");
  printf("i <valor> para inserir valor\n");
  printf("d <valor> para deletar valor\n");
  printf("p         para imprimir em pre ordem\n");
  printf("q         para imprimir em in  ordem\n");
  printf("r         para imprimir em pos ordem\n");
  printf("e         para eliminar valores repetidos\n");
  printf("E         para verificar se eh equilibrada \n");
  printf("M <n>     para imprimir os n maiores valores\n");
  printf("m <n>     para imprimir os n menores valores\n");
  printf("f         para imprimir o vetor de frequencias \n");
  printf("a         para imprimir a altura da arvore\n");
  printf("n         para imprimir o numero de nos da arvore\n");
  printf("I         para imprimir a figura da arvore\n");
  printf("s         para sair do programa\n");
}


int main(int argc, char *argv[])
{
    char option;

    
    ImprimeMenu();
    while ( option != 's' ){
        printf("Opcao: "); option = (char)fgetc(stdin); 
        switch (option){
            case 'i':
                
                break;
            case 'd':
                
                break;
            case 'p':
                break;
            case 'q':
                break;
            case 'r':
                break;
            case 'e':
                break;
            case 'E':
                break;
            case 'M':
                break;
            case 'm':
                break;
            case 'f':
                break;
            case 'a':
                break;
            case 'n':
                break;
            case 'I':
                break;
            default:
                ImprimeMenu();
                break;
        }

    }

    return 0;
}