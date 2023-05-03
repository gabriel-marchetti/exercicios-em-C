#include <stdio.h>

int main(void)
{
    int i = 99, j, *p;
    p = &i;
    j = *p + 100;
    printf("i = %d, j = %d\n", i, j);

    return(0);
}