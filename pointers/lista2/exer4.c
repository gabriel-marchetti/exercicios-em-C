#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 7, j = 3, *p, **r;
    p = &i;
    r = &p;

    int c = *(*r) + j;
    printf("c = %d\n", c);

    return(0);
}