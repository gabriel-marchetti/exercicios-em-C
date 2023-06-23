#include "Graph.h"
// #include "Graph.c"


int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen("input01.txt", "r");
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
    int k = 0;
    for(int i = 0; i < 9; i++){
        floresta[i].label = i;
        floresta[i].custo = INT_MAX;
        floresta[i].pred = NIL;
        k = 0;
        for(int linhas = 0; linhas < n; linhas++){
            for(int colunas = 0; colunas < n; colunas++){
                if( matrix[linhas][colunas] == 1 ){
                    (floresta[i].vizinhos)[k] = colunas;
                    k++;
                }
            floresta[i].nviz = k;
            }
        }
    }


    // Verificando se minha função tá boa:
    printf("------------\n");
    for(int i = 0; i < 9; i++){
        printf("label: %d\n", floresta[i].label);
        printf("predecessor: %d\n", floresta[i].pred);
        printf("custo: %d\n", floresta[i].custo);
        printf("nviz: %d\n", floresta[i].nviz);
        printf("------------\n");
    }

    // Ctl + K -- Ctl + Cs
    // Ctl + K -- Ctl + U
    // for(int i = 0; i < 9; i++){
    //     printf("%d ", floresta[i].label);
    // } printf("\n");
    

    // Questao1(&floresta, 1, NIL, 0, &arr, &arr2);
    // printArray(arr, 9); printArray(arr2, 9);
    buscaLargura(&floresta, 1);
    printf("Predecessor: ");
    for(int i = 0; i < 9; i++){
        printf("%d ", floresta[i].pred);
    } printf("\n");
    printf("Custo: ");
    for(int i = 0; i < 9; i++){
        printf("%d ", floresta[i].custo);
    } printf("\n");

    return 0;
}
