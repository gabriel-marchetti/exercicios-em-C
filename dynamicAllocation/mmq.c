# include <stdio.h>
# include <stdlib.h>

float* arr;
int sizeArr = 256;


int main()
{
    printf("Quantos elementos para a linearização: ");
    scanf("%d", &sizeArr);

    arr = calloc(sizeArr, sizeof(int));
    if (arr = NULL)
    {
        printf("Not allocated.\n");
        exit(0);
    }
    
    
    

    free(arr);
    return(0);
}