# include <stdio.h>
# include <math.h>

# define PI 3.14159

float calculaArea(float raio)
{
    float area = 2*PI*raio*raio;
    return(area);
}

int main()
{
    float raio, area;
    printf("Qual o raio do circulo: ");
    scanf("%f", &raio);

    area = calculaArea(raio);
    printf("A area do seu circulo eh: %f\n", area);

    return(0);
}