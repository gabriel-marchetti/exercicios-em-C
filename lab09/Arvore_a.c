#include "ArvoreBinaria.h"

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
    if ( file == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    /* Modificar para o Scanf no arquivo final. */
    int n;
    fscanf(file, "%d", &n);
    int sim[n], pos[n];
    for(int i = 0; i < n; i++) fscanf(file, "%d", &sim[i]);
    fflush(stdin);
    for(int i = 0; i < n; i++) fscanf(file, "%d", &pos[i]);
    
    // for(int i = 0; i < n; i++){ printf("%d ", sim[i]); printf("%d\n", pos[i]);}

    // Corpo do código.
    arvbin *T = NULL;
    T = createTreeSimPos(sim, pos, n);

    return 0;
}