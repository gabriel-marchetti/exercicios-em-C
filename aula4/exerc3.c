# include <stdio.h>
# include <math.h>

float calculaArea(float a, float b, float c)
{
    float s = (a + b +c)/2;
    s = s*(s-a)*(s-b)*(s-c);
    float area = powf(s, 0.5);

    return(area);
}

int main()
{
    float area, a, b, c, *pA, *pB, *pC;
    pA = NULL; pB = NULL; pC = NULL;

    scanf("%f %f %f", &a, &b, &c);

    if (a == b && b ==c)
    {
        printf("Triangulo Equilatero");
    }
    else if (a == b || b == c || a == c)
    {
        printf("Triangulo Isosceles");
    }
    else
    {
        printf("Triangulo escaleno");
    }

    area = calculaArea(a, b, c);
    printf(" e a sua area eh %.2f\n", area);

    return(0);
}