#include <stdio.h>
#include <stdlib.h>

typedef struct posicao{
    int x;
    int y;
} position;


char **criaMatrixChar(int x, int y)
{
    char **matrix = (char **)calloc(x, sizeof(char *));
    for(int i = 0; i < y; i++){
        matrix[i] = (char *)calloc(1, sizeof(char));
    }
    return matrix;
}


void printMatrix(char **matrix, int x, int y)
{
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}


char **LeLabirinto(FILE *fp, int x, int y, int k)
{
    char **matrix = criaMatrixChar(x,y);
    char lixo;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            fscanf(fp,"%c", &matrix[i][j]);
        }
        fscanf(fp, "%c", &lixo);
    }
    return matrix;
}


position buscaEntrada(char **matrix, int x, int y, int k)
{
    position retorno;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if ( matrix[i][j] == 'E' ){
                retorno.x = i;
                retorno.y = j;
            }
        }
    }
    return retorno;
}


position searchGate(char **matrix, int x, int y, int k)
{
    position gate;
    int i, j;
    gate.x = -1;
    gate.y = -1;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if( matrix[i][j] == 'G' ){
                matrix[i][j] = 'P';
                gate.x = i;
                gate.y = j;
                return gate;
            }
        }
    }
    return gate;
}


void recursionSolve(char **matrix, int x, int y, int k, position *saida, int Xmax, int Ymax)
{
    if ( x < 0 || y < 0 || x >= Xmax || y >= Ymax || matrix[x][y] == 'X' || matrix[x][y] == 'm' ){
        // Estou na borda do labirinto. (ou fora!)
        // Condições que não quero ver novamente...
        return;
    }
    // printf("----------------------\n");
    // printMatrix(matrix, Xmax, Ymax);
    // printf("Posicao: %d %d\n", x, y);
    // printf("----------------------\n");
    if ( matrix[x][y] == 'S' ){
        saida->x = x;
        saida->y = y;
    } else {
        if ( matrix[x][y] == 'G' ){
            matrix[x][y] = 'm';
            // printMatrix(matrix, Xmax, Ymax);
            position gate = searchGate(matrix, Xmax, Ymax, k);
            recursionSolve(matrix, gate.x, gate.y, k, saida, Xmax, Ymax);
        } else {
            matrix[x][y] = 'm';
            recursionSolve(matrix, x - 1, y, k, saida, Xmax, Ymax);
            recursionSolve(matrix, x, y + 1, k, saida, Xmax, Ymax);
            recursionSolve(matrix, x + 1, y, k, saida, Xmax, Ymax);
            recursionSolve(matrix, x, y - 1, k, saida, Xmax, Ymax);
        }
    }
}


position buscaSolucao(char **matrix, int x, int y, int k)
{
    position inicio = buscaEntrada(matrix, x, y, k), saida;
    saida.x = -1; saida.y = -1;

    int entradaX = inicio.x, entradaY = inicio.y;
    recursionSolve(matrix, entradaX, entradaY, k, &saida, x, y);
    
    return saida;
}


int main(int argc, char *argv[])
{
    FILE *fp;
    argv[1] = "test2.txt";
    fp = fopen(argv[1],"r");
    if ( fp == NULL ){
        printf("Could't find the file.\n");
        return -1;
    }

    int x,y,k;
    char **matrix;
    fscanf(fp, "%d %d %d ", &x, &y, &k);
    matrix = LeLabirinto(fp, x, y, k);
    // printf("----------------------\n");
    // printMatrix(matrix, x, y);
    // printf("----------------------\n");
    /* 
    Consegui Salvar a matrix com sucesso!!!!!!
    */
    // printf("----------------------\n");
    position Entrada = buscaEntrada(matrix, x, y, k);
    // printf("Entrada: %d %d\n", Entrada.x, Entrada.y);
    // printf("----------------------\n");
    position saida;
    saida = buscaSolucao(matrix, x, y, k);

    if ( saida.x < 0 || saida. y < 0 ){
        printf("Labirinto sem saida\n");
    } else {
        printf("Encontrou a saida em (%d,%d)\n", saida.y, saida.x);
    }

    return 0;
}