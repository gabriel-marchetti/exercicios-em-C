#include <stdio.h>
#include <stdlib.h>

typedef enum _bool{
    false,
    true
} bool;

typedef struct _listNode{
    int val;
    struct _listNode *next;
}   ListNode, Node;


ListNode *createNode(int elem)
{
    Node *p = (Node *)calloc(1, sizeof(Node));
    p->val = elem;
    p->next = NULL;
    return(p);
}


void addNode( ListNode **lista, int elem )
{
    ListNode *p = createNode(elem);
    ListNode *aux = (*lista);
    if ( *lista == NULL ){
        (*lista) = p;
    } else {
        while (true){
            if ( aux->next == NULL ){
                aux->next = p;
                return;
            }
            aux = aux->next;
        }
    }
}


void printLinkedList(ListNode *LL)
{
    while(LL->next != NULL){
        printf("%d--> ", LL->val);
        LL = LL->next;
    }
    printf("%d-- NULL", LL->val);
    printf("\n");
}


void sameSize( ListNode *l1, ListNode *l2)
{
    int size1, size2, dif;
    size1 = computeSize(l1); size2 = computeSize(l2);
    if(size1 == size2 ){
        return;
    } else if (size1 < size2){
        dif = size2 - size1;
        for(int i = 0; i < dif; i++) addNode(&l1, 0);
    } else {
        dif = size1 - size2;
        for(int i = 0; i < dif; i++) addNode(&l2, 0);
    }
}


int computeSize( ListNode *p)
{
    int size;
    while( p->next != NULL ){
        size++;
        p = p->next;
    }
    size++;
    return(size);
}


ListNode* addTwoNumber( ListNode* l1, ListNode* l2)
{
    int size = 0;
    ListNode *aux = l1;
    while ( aux->next != NULL){
        size++;
        aux = aux->next;
    }
    size++;

    aux = l1;
    int prox = 0;
    int auxInt;
    for (int i = 0; i < size; i++){
        auxInt = aux->val;
        aux->val = (aux->val + l2->val + prox) % 10;
        prox = (auxInt + l2->val)/10;
        if (aux->next != NULL || l2->next != NULL){
            aux = aux->next;
            l2 = l2->next;
        }
    }

    if(prox != 0){
        addNode(l1, prox);
    }
    
    aux = l1;
    printf("[");
    while (aux->next != NULL){
        printf("%d,", aux->val);
        aux = aux ->next;
    }
    printf("%d]\n", aux->val);
    return(l1);
}


int main(void){
    FILE *file;
    file = fopen("exerc2.txt", "r");
    if ( file == NULL ){
        printf("could't find the file\n");
        return(-1);
    }

    int size1, size2;
    fscanf(file, "%d %d", &size1, &size2);

    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    int addValue;
    for(int i = 0; i < size1; i++){
        fscanf(file, " %d", &addValue);
        addNode(&l1, addValue);
    }
    for(int i = 0; i < size2; i++){
        fscanf(file, " %d", &addValue);
        addNode(&l2, addValue);
    }

    printLinkedList(l1);
    printLinkedList(l2);
    l1 = addTwoNumber(l1, l2);
    printLinkedList(l1);

    free(l1); free(l2);
    return(0);
}