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
    
}


int main(void)
{
    ListNode *l1 = NULL, *l2 = NULL;
    int size, add;
    printf("Size: ");
    scanf("%d", &size);
    
    printf("lista 1 ----------\n ");
    for(int i = 0; i < size; i++){
        printf("\t%d: ", i);
        scanf("%d", &add);
        addNode(l1, add);
    }
    printf("lista 2 ----------\n ");
    for(int i = 0; i < size; i++){
        printf("\t%d: ", i);
        scanf("%d", &add);
        addNode(l2, add);
    }


    return(0);
}