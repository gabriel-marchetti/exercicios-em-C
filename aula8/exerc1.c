#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    float pontoX;
    float pontoY;
}   Ponto;


int main()
{
    Ponto P1, P2;
    
    for (int i = 0; i < 1; i++)
    {
        scanf("Ponto1 X: %f", &(P1.pontoX));
        scanf("Ponto1 Y: %f", &(P1.pontoY));
    }
    

    return(0);
}