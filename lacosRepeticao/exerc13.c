# include <stdio.h>

void main()
{
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    int iter, pos;
    iter = 0;
    while (iter < n)
    {
        for (int i = 0; i < iter; i++)
        {
            printf("*");
        }

        printf("+");

        for (int i = iter + 1; i < n; i++)
        {
            printf("*");
        }
        
        printf("\n");
        iter++;
    }
    
    
}