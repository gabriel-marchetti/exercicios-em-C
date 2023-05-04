#include <stdio.h>
#include <stdlib.h>


typedef enum _bool{
    false,
    true
} bool;


typedef struct _ponto{
    float x;
    float y;
} Ponto;


bool checkRegion(Ponto p, Ponto v1, Ponto v2)
{
    if( v1.x < p.x && p.x < v2.x && v1.y < p.y && p.y < v2.y ||
        v1.x < p.x && p.x < v2.x && v2.y < p.y && p.y < v1.y ||
        v2.x < p.x && p.x < v1.x && v1.y < p.y && p.y < v2.y ||
        v2.x < p.x && p.x < v1.x && v2.y < p.y && p.y < v1.y ) {
            return(true);
    } else {
        return(false);
    }
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc3.txt", "r");

    if (fp == NULL){
        return(-1);
    }

    Ponto v1, v2;
    fscanf(fp, "%f %f", &(v1.x), &(v1.y));
    fscanf(fp, "%f %f", &(v2.x), &(v2.y));

    Ponto p;
    fscanf(fp, "%f %f", &(p.x), &(p.y));

    if( checkRegion(p, v1, v2) ){
        printf("Dentro do retângulo.\n");
    } else {
        printf("Fora do retângulo.\n");
    }

    return 0;
}