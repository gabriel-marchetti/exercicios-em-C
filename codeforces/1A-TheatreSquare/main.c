#include <stdio.h>
#include <stdlib.h>


int myCeil( float x ){
    int auxNum = (int)x;
    if ( auxNum == x ){
        return(auxNum);
    } else{
        return(auxNum+1);
    }
}


int main(void)
{
    int n,m,a;
    scanf("%d %d %d", &n, &m, &a);

    float p,q;
    p = (float)n/a;
    q = (float)m/a;
    n = myCeil(p); m = myCeil(q);

    int result = n*m;
    printf("%d\n", result);

    return(0);
}