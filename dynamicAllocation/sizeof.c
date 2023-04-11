# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{
    // returns the size in bytes of a structure;

    int a = 5;
    int arr[3] = {3, 9, 10};

    // for size_t;
    printf("%llu\n", sizeof(a));
    printf("%llu\n", sizeof(arr));


    return(0);
}