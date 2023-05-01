#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("bacon.txt", "r");

    char singleLine[150];
    while (!feof(fp)) {
        fgets(singleLine, 150, fp);
        printf(singleLine);
    }

    fclose(fp);

    return(0);
}