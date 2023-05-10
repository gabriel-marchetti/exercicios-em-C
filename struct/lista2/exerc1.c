#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _ponto{
    float x;
    float y;
    float z;
} ponto;

typedef enum _bool{
    false,
    true,
} bool;


double distPontos(ponto p1, ponto p2)
{
    double aux;
    aux = powf((p1.x - p2.x), 2) + powf((p1.y - p2.y), 2) + powf((p1.z - p2.z), 2);
    return( sqrt(aux));
}


void main(void)
{
    bool cond = true;
    int action;
    ponto p1, p2;
    double dist;
    while(cond){
        printf("[1] - Digitar o valor do primeiro ponto.\n");
        printf("[2] - Digitar o valor do segundo ponto.\n");
        printf("[3] - Mostrar distancias entre os pontos.\n");
        printf("[4] - Sair.\n");
        scanf("%d", &action);
        switch (action){
        case 1:
            printf("Digite os valores(X Y Z): ");
            scanf("%f %f %f", &p1.x, &p1.y, &p1.z);
            break;
        case 2:
            printf("Digite os valores(X Y Z): ");
            scanf("%f %f %f", &p2.x, &p2.y, &p2.z);
            break;
        case 3:
            dist = distPontos(p1, p2);
            printf("Distancia: %.2f\n", dist);
            break;
        default:
            cond = false;
            break;
        }
    }
}