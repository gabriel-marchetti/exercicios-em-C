/*==DEFINING_FUNCTION==*/
int **createMatrix(int size)
{
    int **matrix = (int **)calloc(size, sizeof(int *));
    for(int i = 0; i < size; i++){
        matrix[i] = (int *)calloc(size, sizeof(int));
    }
    return (matrix);
}

void printMatrix(int **matrix, int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}