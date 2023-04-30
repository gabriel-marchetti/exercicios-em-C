#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node_list{
    int elem;
    struct _node_list *next;
} nodeList, simpleList;

nodeList *createNode(int elem);
void destroyList(simpleList *start);
bool checkEmptyList(simpleList *start);
void printSimpleList(simpleList *start);
bool searchElementSimpleList(simpleList *start, int elem);
void insertBeginList(simpleList *start, int elem);


nodeList *createNode(int elem){
    nodeList *node = (nodeList *)calloc(1, sizeof(nodeList));
    node->elem = elem;
    node->next = NULL;
    return(node);
}


void destroyList(simpleList *start){
    nodeList *p = start, *ant = NULL;
    bool condition = checkEmptyList(start);
    if (condition == false){
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
    if ( start != NULL ){
        nodeList *p = start;
        while (p->next != NULL){
            printf("%d -->", p->elem);
            p = p->next;
        }
        printf("%d\n", p->elem);
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


void insertBeginList(simpleList *start, int elem){
    nodeList *p = createNode(elem), *q = start->next;
    start = p;
    p->next = q;
}


int main(void){
    simpleList *head=NULL;
    int elem, option;

    while(1){
        printf("Entre com uma opcao: \n");
        printf("0 - Insere elemento no começo da lista.\n");
        printf("1 - Insere elemento no final da lista\n");
        printf("2 - Insere antes de uma chave.\n");
        printf("3 - Imprime a lista.\n");
        printf("\n");

        printf("Faça sua escolha: "); scanf("%d", &option);
        switch (option){
        case 0:
            printf("Adicione o elemento: "); scanf("%d", &elem);
            if (head == NULL){
                head = createNode(elem);
            } else {
                // Adiciono o elemento no começo da lista.
                // Criar função que adiciona no começo da lista.
                insertBeginList(head, elem);
            }
            printf("\n");
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
        case 3:
            if (head != NULL){
                printSimpleList(head);
            } else {
                printf("A lista está vazia.\n");
            }
            printf("\n");
            break;
        default:
            return(1);
            break;
        }
    }

    destroyList(head);
    return(0);
}