# include <stdio.h>
# include <malloc.h>


int main()
{
    float **m = (float **)calloc(5, sizeof(float *));
    for (int i = 0; i < 5; i++)
    {
        m[i] = (float *)calloc(3, sizeof(float));
    }
    
    m[0][0] = 2.5;
    float **a, *b, c;
    a = m; 
    b = (a[0] + 1); // m[0] + 1 => m[0][1]
    b[0] = 5.5; // m[0][1] => 5.5
    c = *b;

    for ( int i = 0; i < 5; i++)
    {
        free(m[i]);
    }
    free(m);

    return(0);
}