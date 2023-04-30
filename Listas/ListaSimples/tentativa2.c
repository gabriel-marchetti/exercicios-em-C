#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int elem;
    struct _node* next;
} node, linkedList;


node* createNode(int elem){
    node *p = (node *)calloc(1, sizeof(node));
    p->elem = elem;
    p->next = NULL;
    return(p);
}


void append(node *root, int elem){
    node *p = createNode(elem), *q = root;
    while ( q->next != NULL){
        q = q->next;
    }
    q->next = p;
}


void printLinkedList(node *root){
    node *p = root;
    while ( p->next != NULL){
        printf(" %d -->", p->elem);
        p = p->next;
    }
    printf(" %d --> NULL \n", p->elem);
    printf("\n");
}


int main(){
    node *root;
    int elem, option;
    printf("Adicione o primeiro elemento: "); scanf("%d", &elem);
    root = createNode(elem);

    while(1){
        printf("1 - Append no elemento.\n");
        printf("2 - Imprime a lista.\n");
        printf("# - Sair.\n");
        printf("\n");
        
        printf("Sua escolha: "); scanf("%d", &option);
        switch (option){
        case 1:
            printf("Adicione um elemento: "); scanf("%d", &elem);
            append(root, elem);
            printf("\n");
            break;
        case 2:
            printLinkedList(root);
            break;
        default:
            return(0);
            break;
        }
    }

    return(0);
}