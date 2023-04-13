#include <stdio.h>
#include <stdlib.h>


typedef enum{
    false,
    true,
} bool;


char **createMatrix(int line, int column){
    char **matrix = (char **)calloc(line, sizeof(char *));
    for (int i = 0; i < line; i++)
    {
        matrix[i] = (char *)calloc(column, sizeof(char));
    }
    return(matrix);
}


void destroyMatrix(char ***matrix, int line){
    if(*matrix != NULL){
        for (int i = 0; i < line; i++)
        {
            free(*matrix[i]);    
        }
        free(*matrix);
        *matrix = NULL;
    }
}


void insertingBombs(char ***minefield, int posLine, int posCol, int radius, int rangeline, int rangecol){
    for (int i = posLine - radius; i <= posLine + radius; i++){
        for (int j = posCol - radius; j <= posCol + radius; j++)
        {
            if (i < 0 || i > rangeline || j < 0 || j > rangecol)            {
                continue;
            } else {
                *minefield[i][j] = 'P';
            }
        }
    }
}


bool checkMinefield(char ***minefield, int line, int col){
    if ( *minefield[line][col] == 'P'){
        return(false);
    } else {
        return(true);
    }
}

int main(){
    // Vou indicar um quadrado seguro com '\0' pois já está inicializado nesse valor.
    // Vou indicar um quadrado perigoso com P.
    int line, column, bombs;
    char **minefield;

    // Salvando os valores.
    scanf("%dx%d", &line, &column);
    scanf("%d", &bombs);
    if (line < 0 || column < 0 || bombs < 0){
        // Input Inválido
        return(-1);
    }
    
    // Preciso criar a matriz do campo de batalha.
    minefield = createMatrix(line, column);
    
    // Posicionando as bombas.
    int posLine, posCol, radius;
    for (int i = 0; i < bombs; i++){
        scanf("%d %d %d", &posLine, &posCol, &radius);
        if (posLine < 0 || posCol < 0 || radius < 0)
        {
            // Input Inválido
            return(-1);
        }
        insertingBombs(&minefield, posLine, posCol, radius, line, column);
    }

    int tankLine, tankCol;
    scanf("%d %d", &tankLine, &tankCol);
    if (tankLine < 0 || tankCol < 0)
    {
        // Input Inválido
        return(-1);
    }
    bool veredict;
    veredict = checkMinefield(&minefield, tankLine, tankCol);
    if (veredict)
    {
        printf("Seguro");
    } else {
        printf("Perigoso");
    }

    destroyMatrix(&minefield, line);
    return(0);
}