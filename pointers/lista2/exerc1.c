#include <stdio.h>
#include <stdlib.h>


void misterio(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}


int main(void)
{
    int i = 6, j = 10;
    printf("i = %d, j = %d", i, j);    

    misterio(&i, &j);

    printf("i = %d, j = %d", i, j);

    return(0);
}