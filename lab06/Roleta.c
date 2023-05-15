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

    char action; 
    
    /*
    test[] = { '0', '1', '2', '3', '4',
                            '5', '6', '7', '8', '9',
                            '+', 'D', 'C', 'I'} ; 
    */

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

    destroiPilha(&pil);
    return(0);
}
