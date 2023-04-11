# include <stdio.h>

int main()
{
    int numbers[5] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 5; i++)
    {
        printf("%d = %p\n", numbers[i], &numbers[i]);
    }
    
    printf("Array addres of 1: %p\n", numbers);
    printf("Array addres of 2: %p\n", numbers + 1);
    printf("Array addres of 3: %p\n", numbers + 2);
    printf("Array addres of 4: %p\n", numbers + 3);

    

    return(0);
}