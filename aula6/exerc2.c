# include <stdio.h>
# include <stdlib.h>


int main()
{
    char* s1 = "MC202"; // no stack -- Read-Only
    char s2[6] = {'M', 'C', '2', '0', '2'}; // feito no stack
    char* s3 = (char *)calloc(6, sizeof(char));


    return(0);
}