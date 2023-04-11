# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

int verificaPrimo(int x)
{
    int i = 2;
    while ( i <= x/2)
    {
        if (x % i == 0)
        {
            return(0);
        }
        i++;
    }
    return(1);
    
}

void primosMenoresIguais(int x)
{
    if (x < 2)
    {
        printf("Numero invalido\n");
        exit(1);
    }

    for (int i = 2; i <= x; i++)
    {
        int z;
        z = verificaPrimo(i);
        if (z == 1)
        {
            printf("O numero %d eh primo\n", i);
        }
    }
    

}

int main()
{
    int primo;

    printf("Valor desejado: ");
    scanf("%d", &primo);

    
    primosMenoresIguais(primo);

    return(0);
}