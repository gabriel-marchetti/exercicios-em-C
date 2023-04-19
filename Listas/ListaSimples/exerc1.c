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
    }

    return(0);
}