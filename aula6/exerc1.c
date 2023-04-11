# include <stdio.h>
# include <stdlib.h>

int main()
{
    char texto[100];

    sprintf(texto, "MC202");
    sprintf(texto + 5, "-ABC");
    printf("%s \n", texto);

    return(0);
}