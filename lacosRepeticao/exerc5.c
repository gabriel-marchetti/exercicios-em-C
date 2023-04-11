# include <stdio.h>
# include <stdbool.h>

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);

    while (true)
    {
        y = ( x % 2 ) + 10 * y;
        x = x / 2;
        printf("x = %d y = %d\n", x, y);
        if (x == 0)
        {
            break;
        }   
    }

    while ( y != 0)
    {
        x = y % 100;
        y = y / 10;
        printf("x = %d y = %d\n", x, y);
    }
    
}