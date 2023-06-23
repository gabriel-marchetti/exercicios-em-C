#include "Graph.h"


int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Could't find the file.\n");
        return -1;
    }

    /*--STORE_MATRIX--*/
    int n, storage, **matrix;
    fscanf(file,"%d", &n);
    matrix = createMatrix(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(file,"%d ", &storage);
            matrix[i][j] = storage;
        }
    }
    // printMatrix(matrix, n);
    // Consegui Salvar a Matrix!

    

    return 0;
}
