# include <stdio.h>
# include <stdlib.h>

int* arr;
size_t arrSize = 256;

// Question to make when using dynamic allocation:
// 1) Do you know the maximum size of the array
// 2) Is your list too big
// 3) Are you going to use it in many places


int main()
{
    arr = calloc(arrSize, sizeof(int));
    if (arr == NULL)
    {
        printf("Erro!\n");
        return(-1);
    }

    arrSize *= 2;
    arr = realloc(arr, arrSize * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro!\n");
        return(-1);
    }

    free(arr);
    return(0);
}