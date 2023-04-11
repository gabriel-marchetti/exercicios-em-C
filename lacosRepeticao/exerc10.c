# include <stdio.h>

int main()
{
    int n, rem, bin, base;

    scanf("%d", &n);
    bin = 0;
    base = 1;

    while (n != 0)
    {        
        rem = n % 2;
        n = n / 2;
        bin = bin + (base * rem);
        base = base * 10;
    }
    
    printf("%d", bin);
    

    return(0);
}