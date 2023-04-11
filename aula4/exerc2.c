# include <stdio.h>

void trocaValores(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

}

int main()
{
    int valor1, valor2;

    scanf("%d %d", &valor1, &valor2);

    printf("-----------------\n");
    printf("a: %d | b: %d\n", valor1, valor2);
    trocaValores(&valor1, &valor2);
    printf("a: %d | b: %d\n", valor1, valor2);
    


    return(0);
}