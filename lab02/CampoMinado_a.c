#include <stdio.h>
#include <stdlib.h>


typedef enum{
    false,
    true,
} bool;


typedef struct _bombs{
    int line;
    int col;
    int rad;
} Bomb;


Bomb *criaBomba(){
    Bomb *b = (Bomb *)calloc(1, sizeof(Bomb));
    return(b);
}

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
            free((*matrix)[i]);    
        }
        free(*matrix);
        *matrix = NULL;
    }
}


void insertingBombs(char ***minefield, int posLine, int posCol, int radius, int rangeline, int rangecol){
    for (int i = posLine - radius; i <= posLine + radius; i++){
        for (int j = posCol - radius; j <= posCol + radius; j++)
        {
            if (i < 0 || i >= rangeline || j < 0 || j >= rangecol){
                continue;
            } else {
                (*minefield)[i][j] = 'P';
            }
        }
    }
}


bool checkMinefield(char ***minefield, int line, int col){
    if ( (*minefield)[line][col] == 'P'){
        return(false);
    } else {
        return(true);
    }
}

int main(){
    // Vou indicar um quadrado seguro com '\0' pois já está inicializado nesse valor.
    // Vou indicar um quadrado perigoso com P.
    int line, column, nbombs;
    char **minefield;

    // Salvando os valores.
    scanf("%dx%d", &line, &column);
    scanf("%d", &nbombs);
    if (line < 0 || column < 0 || nbombs < 0){
        // Input Inválido
        printf("-1\n");
        return(0);
    }
    
    // Preciso criar a matriz do campo de batalha.
    minefield = createMatrix(line, column);
    
    // Posicionando as bombas.
    Bomb *bombs = criaBomba();
    for (int i = 0; i < nbombs; i++){
        scanf("%d %d %d", &bombs->line, &bombs->col, &bombs->rad);
        if (bombs->line < 0 || bombs->col < 0 || bombs->rad < 0 ||
            bombs->line > line || bombs->col > column)
        {
            // Input Inválido
            printf("-1\n");
            return(0);
        }
        insertingBombs(&minefield, bombs->line, bombs->col, bombs->rad, line, column);
    }

    int tankLine, tankCol;
    scanf("%d %d", &tankLine, &tankCol);
    if (tankLine < 0 || tankCol < 0 || tankLine > line || tankCol > column)
    {
        // Input Inválido
        printf("-1\n");
        return(0);
    }
    bool veredict;
    veredict = checkMinefield(&minefield, tankLine, tankCol);
    if (veredict)
    {
        printf("Seguro\n");
    } else {
        printf("Perigoso\n");
    }

    destroyMatrix(&minefield, line);
    free(bombs);
    return(0);
}