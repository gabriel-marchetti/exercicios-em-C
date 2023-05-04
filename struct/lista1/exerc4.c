#include <stdio.h>
#include <stdlib.h>


typedef struct _vetor{
    float x;
    float y;
    float z;
} Vetor;


Vetor SomaVetores(Vetor v1, Vetor v2)
{
    Vetor p;
    p.x = v1.x + v2.x;
    p.y = v1.y + v2.y;
    p.z = v1.z + v2.z;

    return(p);
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc4.txt", "r");

    if ( fp == NULL ){
        printf("Não encontrei o arquivo.\n");
        return(-1);
    }

    Vetor v1, v2;
    fscanf(fp, "%f %f %f", &(v1.x), &(v1.y), &(v1.z));
    fscanf(fp, "%f %f %f", &(v2.x), &(v2.y), &(v2.z));

    Vetor v_soma;
    v_soma = SomaVetores(v1, v2);
    
    printf("x: %.2f, y: %.2f, z: %.2f\n", v_soma.x, v_soma.y, v_soma.z);

    return(0);
}