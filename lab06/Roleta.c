#include "Pilha.h"


int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return(-1);
    }

    int n;
    fscanf(file, "%d ", &n);

    char action, test[] = { '0', '1', '2', '3', '4',
                            '5', '6', '7', '8', '9',
                            '+', 'D', 'C', 'I'} ; 
    pilha *pil = NULL, *auxP;
    int aux;
    while(n){
        fscanf(file, "%c", &action);
        /*
        for( int i = 0; i < 14; i++){
            if( action != test[i] ){
                printf("Invalid action.\n");
                return(-1);
            }
        }
        */

        switch (action){
        case '+':
            auxP = pil;
            aux = ((int)pil->ch);
            auxP = auxP->next;
            aux = aux + (int)auxP->ch;
            n--;
            break;
        case 'D':
            aux = (int)pil->ch;
            aux = 2*aux;
            action = (char)aux;
            empilha(&pil, action);
            n--;
            break;
        case 'C':
            desempilha(&pil);
            n--;
            break;
        case 'I':
            aux = (int)pil->ch;
            aux = -aux;
            action = (char)aux;
            if( pil == NULL ){
                printf("There is no element for converting its sign.\n");
            } else {
                pil->ch = action;
            }
            n--;
            break;
        default:
            empilha(&pil, action);
            n--;
            break;
        }
    }

    aux = calculaPilha(pil);
    printf("%d", aux);



    return(0);
}

pilha *criaPilha()
{
    pilha *p = (pilha *)calloc(1, sizeof(pilha));
    return(p);
}

void empilha(pilha **pil, char letra)
{
    pilha *ad;
    if ( *pil == NULL ){
        *pil = criaPilha();
    } else {
        ad = (pilha *)calloc(1, sizeof(pilha));
        ad->ch = letra;
        ad->next = *pil;
        *pil = ad;
    }
}

void desempilha(pilha **pil)
{
    pilha *ad = NULL;
    if ( *pil == NULL ){
        return;
    } else if ( (*pil)->next == NULL ){
        free((*pil));
    } else {
        ad = *pil;
        *pil = (*pil)->next;
        free(ad);
    }
}

int calculaPilha(pilha *pil)
{
    int retorno = 0;
    while(pil->next != NULL){
        retorno = retorno + (int)pil->ch;
        pil = pil->next;
    }
    retorno = retorno + (int)pil->ch;
}

void destroiPilha(pilha **pil)
{
    pilha *ad = NULL;
    while ((*pil)->next != NULL){
        ad = *pil;
        *pil = (*pil)->next;
        free(ad);
    }
    free(pil);
}