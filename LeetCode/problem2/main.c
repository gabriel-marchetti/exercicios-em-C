#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedlist{
    int info;
    struct _linkedlist *next;
} linkedlist, nodeLL;


/* PROTOTIPAGEM */
void addNode(linkedlist **ll, int info);
void printList(linkedlist *ll);
linkedlist *addTwoNumbers( linkedlist *l1, linkedlist *l2, int remainder);


/* Especificando funções */
void addNode(linkedlist **ll, int info)
{
    linkedlist *addNode = (linkedlist *)calloc(1, sizeof(linkedlist));
    addNode->info       = info;
    addNode->next       = NULL;
    linkedlist *current = *ll;
    if (*ll == NULL){
        *ll = addNode;
    } else {
        while ( current->next != NULL ) current = current->next;
        current->next = addNode;
    }
}

void printList(linkedlist *ll)
{
    while ( ll != NULL ){
        printf("%d ", ll->info);
        ll = ll->next;
    }
    printf("\n");
}

linkedlist *addTwoNumbers( linkedlist *l1, linkedlist *l2, int remainder)
{
    if ( l1 == NULL && l2 == NULL){
        if ( remainder > 0 ){
            linkedlist *extraNode = (linkedlist *)calloc(1, sizeof(linkedlist));
            extraNode->info = remainder;
            return extraNode;
        } else {
            return NULL;
        }
    }
    linkedlist *currentNode = (linkedlist *)calloc(1, sizeof(linkedlist));
    int info;
    if ( l1 == NULL ){
        info = l2->info + remainder;
    } else if ( l2 == NULL ){
        info = l1->info + remainder;
    } else {
        info = l1->info + l2->info + remainder;
    }
    remainder = info / 10;
    info = info % 10;

    currentNode->info = info;
    if ( l1 ==  NULL ){
        currentNode->next = addTwoNumbers(NULL, l2->next, remainder);
    } else if ( l2 == NULL ){
        currentNode->next = addTwoNumbers(l1->next, NULL, remainder);
    } else {
        currentNode->next = addTwoNumbers(l1->next, l2->next, remainder);
    }
    return currentNode;
}

void printFormated(linkedlist *ll)
{
    printf("[");
    while(ll->next != NULL ){
        printf("%d,", ll->info);
        ll = ll->next;
    }
    printf("%d]", ll->info);
    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *file;
    char filename[20];
    int n, insere;

    printf("File to open for the first list:\n");
    scanf("%s", filename);
    // printf("%s\n", filename);
    file = fopen(filename, "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    /* Transferir o .txt para um linkedlist */
    linkedlist *l1 = NULL;
    fscanf(file, "%d ", &n);
    for(int i=0; i < n; i++){
        fscanf(file, "%d ", &insere);
        addNode(&l1, insere);
    }
    printf("First linkedlist: \n");
    printList(l1);
    fclose(file);
    /*-------------------------*/
    printf("File to open for the second list:\n");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }
    linkedlist *l2 = NULL;
    fscanf(file, "%d ", &n);
    for(int i=0; i < n; i++){
        fscanf(file, "%d ", &insere);
        addNode(&l2, insere);
    }
    printf("Second linkedlist: \n");
    printList(l2);
    fclose(file);
    /*------------------------*/
    linkedlist *finalLL = NULL;
    finalLL = addTwoNumbers(l1, l2, 0);
    printf("Result: \n");
    printFormated(finalLL);

    return 0;
}