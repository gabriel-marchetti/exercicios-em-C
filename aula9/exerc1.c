#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fatorial(int num)
{
    if (num == 1)
    {
        return(1);
    }
    else 
    {
        return(num * fatorial(num - 1));
        
    }
}

/* Primeira aula do curso, veremos recursão */
int main()
{
    int num;
    printf("Digite o numero: ");
    scanf(" %d", &num);
    num = fatorial(num);

    printf("Valor eh %d\n", num);
    return(0);
}