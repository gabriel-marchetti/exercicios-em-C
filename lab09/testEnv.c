#include "ArvoreBinaria.h"


int main(int argc, char *argv[])
{
    printf("Rodando...\n");
    int array[] = {100, 90, 110, 120, 95, 80, 105};
    arvbin *T = NULL;
    for (int i = 0; i < 7; i++) insertNode(&T, array[i]);
    printf("------------------------\n");
    printBinaryTree(T, 0);
    printf("------------------------\n");
    printf("InOrder: \n");
    inOrder(T);
    printf("\n");
    printf("posOrder: \n");
    posOrder(T);
    printf("\n");
    printf("PreOrder: \n");
    preOrder(T);
    printf("\n");

    int sim[] = {80, 90, 95, 100, 105, 110, 120};
    int pos[] = {80, 95, 90, 105, 120, 110, 100};
    int pre[] = {100, 90, 80, 95, 110, 105, 120};
    arvbin *T2 = createTreeSimPos(sim, pos, 7);
    printf("------------------------\n");
    printBinaryTree(T2, 0);
    printf("------------------------\n");
    arvbin *T3 = invertTree(T2);
    printf("------------------------\n");
    printBinaryTree(T3, 0);
    printf("------------------------\n");
}