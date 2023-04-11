# include <stdio.h>

int main()
{
    int C;

    scanf("%d", &C);

    for (int x1 = 0; x1 <= C; x1++)
    {
        for (int x2 = 0; x2 <= C - x1; x2++)
        {
            int x3;
            x3 = C - x1 - x2;
            printf("%d + %d + %d = %d\n", x1, x2, x3, C);   
        }
        
    }
    

    return(0);
}