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
    nodeGraph *floresta = (nodeGraph *)calloc(9, sizeof(nodeGraph));
    for(int i = 0; i < 9; i++){
        floresta[i].label = i;
        floresta[i].custo = INT_MAX;
        floresta[i].pred = NIL;
        for(int linhas = 0; linhas < n; linhas++){
            int k=0;
            for(int colunas = 0; colunas < n; colunas++){
                if( matrix[linhas][colunas] == 1 ){
                    floresta[i].vizinhos[k] = colunas;
                    k++;
                }
            floresta[i].nviz = k;
            }
        }
    }


    // Ctl + K -- Ctl + C
    // Ctl + K -- Ctl + U
    // for(int i = 0; i < 9; i++){
    //     printf("%d ", floresta[i].label);
    // } printf("\n");
    

    Questao1(&floresta, 1, NIL, 0, &arr, &arr2);
    printArray(arr, 9); printArray(arr2, 9);

    return 0;
}
