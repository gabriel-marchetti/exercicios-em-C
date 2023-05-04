#include <stdio.h>
#include <stdlib.h>


typedef struct _ponto{
    float x;
    float y;
}   Ponto;


void deltas(float v1[2], float v2[2], float *deltaX, float *deltaY)
{
    
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc3.txt", "r");

    if( fp == NULL ){
        printf("Não encontrei o arquivo.");
        return(-1);
    }

    float *deltaX = NULL, *deltaY = NULL;
    float v1[2], v2[2];

    fscanf(fp, "%f %f", &v1[0], &v1[1]);
    fscanf(fp, "%f %f", &v2[0], &v2[1]);

    return(0);
}