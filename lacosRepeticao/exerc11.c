# include <stdio.h>

void main()
{
    int n, j;
    j = 1;

    scanf("%d", &n);

    while ( j <= n)
    {
        for (int i = 1; i < j; i++)
        {
            printf("%d ", i);
        }

        printf("%d\n", j);
        j++;
        
    }
    
}