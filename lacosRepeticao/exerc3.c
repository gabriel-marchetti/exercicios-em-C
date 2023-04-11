# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>

int MDC(int m, int n)
{
    if ( m < 0 || n < 0)
    {
        printf("Não são números inteiros positivos!\n");
        exit(1);
    }
    else if (m == 0)
    {
        return(n);
    }
    else if (n == 0)
    {
        return(m);
    }
    else if (m > n)
    {
        MDC(n, m-n);
    }
    else 
    {
        MDC(m, n-m);
    }
    
}

int main()
{
    int m, n, mdc, *pM, *pN;
    pM = &m; pN = &n;

    printf("Valores de m e n: ");
    scanf("%d %d", &m, &n);

    mdc = MDC(m, n);
    
    printf("O valor do MDC eh: %d\n", mdc);

    return 0;
}