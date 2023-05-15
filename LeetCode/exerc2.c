#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode{
    int val;
    struct _listNode *next;
} ListNode;


ListNode *createNode(int elem)
{
    ListNode *p = (ListNode *)malloc(1 * sizeof(ListNode));
    p->val = elem;
    p->next = NULL;
    return(p);
}

void addNode(ListNode *linkedList, int val)
{
    ListNode *exp = linkedList, *add = createNode(val);
    if( linkedList == NULL ){
        createNode(val);
    } else {
        while(exp->next != NULL){
            exp = exp->next;
        }
        exp->next = add;
    }
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

    int prox = 0;
    int auxInt;
    for (int i = 0; i < size; i++){
        auxInt = l1->val;
        l1->val = (l1->val + l2->val + prox) % 10;
        prox = (auxInt + l2->val)/10;
        if (l1->next != NULL || l2->next != NULL){
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    
    return(l1);
}


void imprimeLista(ListNode *l, int size)
{
    for(int i = 0; i < size; i++){
        printf("%d --> ", l->val);
        l = l->next;
    }
}


int main(void)
{
    ListNode *l1 = NULL, *l2 = NULL;
    l1 = (ListNode *)malloc(sizeof(ListNode));
    l2 = (ListNode *)malloc(sizeof(ListNode));
    int size, add;

    printf("Size: ");
    scanf("%d", &size);
    
    printf("lista 1 ----------\n ");
    for(int i = 0; i < size; i++){
        printf("\t%d:", i);
        scanf(" %d", &add);
        addNode(l1, add);
    }
    printf("lista 2 ----------\n ");
    for(int i = 0; i < size; i++){
        printf("\t%d:", i);
        scanf(" %d", &add);
        addNode(l2, add);
    }
    imprimeLista(l1, size); printf("\n");
    imprimeLista(l2, size); printf("\n");
    addTwoNumber(l1, l2);
    imprimeLista(l1, size); printf("\n");

    free(l1); free(l2);
    return(0);
}