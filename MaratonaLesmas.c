# include <stdio.h>
# include <stdlib.h>

int retornaMaximo(int *lista)
{
    int max;
    max = 0;

    for (int i = 0; i < 100; i++)
    {
        if (max < lista[i])
        {
            max = lista[i];
        }
    }
    
    return(max);
}

int main()
{
    int n, velocidadeLesma, tempo, *lista1, *lista2, *lista3;
    // lista1 : lista das lesmas que podem competir em 1
    // lista2 : lista das lesmas que podem competir em 2
    // lista3 : lista das lesmas que podem competir em 3 

    lista1 = (int *)calloc(100, sizeof(int));
    lista2 = (int *)calloc(100, sizeof(int));
    lista3 = (int *)calloc(100, sizeof(int));

    scanf("%d", &n);
    if (n < 0 || n >= 100)
    {
        return(-1);
    }


    int posicao1, posicao2, posicao3;
    posicao1 = 0; posicao2 = 0; posicao3 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &velocidadeLesma);

        if (velocidadeLesma < 0)
        {
            continue;
        }
        else if (velocidadeLesma <= 10)
        {
            lista1[posicao1] = velocidadeLesma;
            posicao1++;
        }
        else if (velocidadeLesma <= 20)
        {
            lista2[posicao2] = velocidadeLesma;
            posicao2++;
        }
        else if (velocidadeLesma <= 100)
        {
            lista3[posicao3] = velocidadeLesma;
            posicao3++;
        }
    }

    scanf("%d", &tempo);
    
    if (tempo == 1)
    {
        printf("%d\n", retornaMaximo(lista3));
    }
    else if (tempo == 2)
    {
        printf("%d\n", retornaMaximo(lista2));
    }
    else if (tempo == 3)
    {
        printf("%d\n", retornaMaximo(lista1));
    }
    else
    {
        return(-1);
    }



    return(0);
}