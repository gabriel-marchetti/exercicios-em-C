#include <stdio.h>

int main(void)
{
    int a = 5, b = 12;
    int *p, *q;
    p = &a; q = &b;
    int c = *p + *q;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return(0);
}