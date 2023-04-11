#include <stdio.h>
#include <stdlib.h>


int produto(int x1, int xn)
{
    if ( x1 == xn )
    {
        return(xn);
    }
    else if ( x1 < xn )
    {
        return( produto(x1, (x1 + xn)/2) * produto((x1+xn)/2 + 1, xn));
    }
    else
    {
        return( produto(xn, (x1 + xn)/2) * produto((x1+xn)/2 + 1, x1));
    } 
}

/* Resolvendo o problema por indução forte */
int main()
{
    int num;
    scanf("%d", &num);

    num = produto(1, num);
    printf("Valor: %d\n", num);   

    return(0);
}