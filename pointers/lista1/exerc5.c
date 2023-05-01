#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("exerc5.txt", "r");

    if (fp == NULL){
        printf("Não foi encontrado o arquivo\n");
        return(-1);
    }

    int a, b, *p1, *p2;
    fscanf(fp, "%d", &a); fscanf(fp, "%d", &b);
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;

    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);

    return(0);
}