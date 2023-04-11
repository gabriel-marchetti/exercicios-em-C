# include <stdio.h>
# include <stdlib.h>

int main()
{
    int n, valor, i1, i2, i3, i4;
    i1 = 0; i2 = 0; i3 = 0; i4 = 0;
    
    scanf("%d", &n);

    scanf("valor: %d", &valor);
    for ( int i = 0; i < n; i++)
    {   if ( 0 <= valor && valor <= 25)
        {
            i1++;
        }
        else if (26 <= valor && valor <= 50)
        {
            i2++;
        }
        else if (51 <= valor && valor <= 75)
        {
            i3++;
        }
        else if (76 <= valor && valor <= 100)
        {
            i4++;
        }
        else
        {
            continue;
        }
        scanf("valor: %d", &valor);
    }

    printf( "[0, 25] : %d\n[26, 50] : %d\n[51, 75] : %d\n[76, 100] : %d\n", i1, i2, i3, i4);

    return(0);
}