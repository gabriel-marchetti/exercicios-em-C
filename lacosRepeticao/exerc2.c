# include <stdio.h>
# include <stdbool.h>
# include <math.h>

int main()
{
    int n, maximo, numero;

    printf("Valor de n: ");
    scanf("%d", &n);

    for ( int i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        if( i == 0 )
        {
            maximo = numero;
        }
        else if (numero > maximo)
        {
            maximo = numero;
        }
        else
        {
            continue;
        }
        
    }

    printf("O valor maximo da lista: %d\n", maximo);
    

    return(0);
}