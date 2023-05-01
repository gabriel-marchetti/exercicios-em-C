#include <stdio.h>
#include <stdlib.h>


void func(int *px, int *py)
{
    px = py;
    *py = (*py) * (*px);
    *px = *px + 2;
}


int main(void)
{
    FILE *fp;
    fp = fopen("exerc4.txt", "r");

    int x, y;
    fscanf(fp, "%d", &x);
    fscanf(fp, "%d", &y);

    func(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return(0);
}