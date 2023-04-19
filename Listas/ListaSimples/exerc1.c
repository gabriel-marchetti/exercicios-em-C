#include <stdio.h>
#include <stdlib.h>


typedef enum _bool{
    false,
    true
} bool;


typedef struct _node_list{
    int elem;
    struct _node_list *next;
} nodeList, simpleList;


nodeList *createNode(int elem){
    nodeList *node = (nodeList *)calloc(1, sizeof(nodeList));
    node->elem = elem;
    node->next = NULL;
    return(node);
}


void destroyList(simpleList *start){
    nodeList *p = start, *ant = NULL;
    if (!(checkEmptyList(start))){
        while (start->next != NULL){
            p = start->next;
            ant = start;
            start = p;
            free(ant);
        }
        free(p);
    }
}

bool checkEmptyList(simpleList *start){
    if (start->next == NULL){
        return(true);
    } else {
        return(false);
    }
}


void printSimpleList(simpleList *start){
    if (!(checkEmptyList(start))){
        while (start->next != NULL){
            printf("%d -->", start->elem);
            start = start->next;
        }
        printf("%d\n", start->elem);
    }
}


bool searchElementSimpleList(simpleList *start, int elem){
    if (checkEmptyList == false){
        nodeList *p = start;
        while (p->next != NULL){
            if (elem == p->elem){
                return(true);
            }
        }
        if ((*p).elem == elem){
            return(true);
        } else {
            return(false);
        }
    } else {
        return(false);
    }
}


int main(void){
    simpleList *head=NULL;
    int elem, option;

    while(1){
        printf("Entre com uma opcao: \n");
        printf("0 - Insere elemento no começo da lista.\n");
        printf("1 - Insere elemento no final da lista\n");
        printf("2 - Insere antes de uma chave.\n");
        printf("\n");

        scanf("%d", &option);
        switch (option){
        case 0:
            printf("Adicione o elemento: "); scanf("%d", &elem);
            if (head == NULL){
                head = createNode(elem);
            } else {
                // Adiciono o elemento no começo da lista.
                // Criar função que adiciona no começo da lista.

            }
            break;
        case 1:
            printf("Adicione o elemento: "); scanf("%d", &elem);
            if (head == NULL){
                head = createNode(elem);
            } else {
                // Adiciono o elemento no final da lista.
                // Criar função que adiciona no final da lista.
            }
            break;
        case 2:

            break;
        default:
            break;
        }
    }
    return(0);
}