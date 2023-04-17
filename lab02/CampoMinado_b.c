#include <stdio.h>
#include <stdlib.h>


typedef struct _tank{
    int posX;
    int posY;
    int res; // resistência do tank
} Tank;


Tank *createTank(){
    Tank *tank = (Tank *)calloc(1, sizeof(Tank));
    return(tank);
}


int **createMatrix(int line, int col){
    int **matrix = (int **)calloc(line, sizeof(int*));
    for (int i = 0; i < line; i++){
        matrix[i] = (int *)calloc(col, sizeof(int));
    }
    return(matrix);
}


void destroyMatrix(int ***matrix, int line){
    for (int i = 0; i < line; i++){
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}


void insertingBombs(int ***matrix, int posLine, int posCol, int radius, int rangeline, int rangecol){
    for (int i = posLine - radius; i <= posLine + radius; i++){
        for (int j = posCol - radius; j < posCol + radius; j++){
            if (i < 0 || i >= rangeline || j < 0 || j >= rangecol){
                continue;
            } else {
                (*matrix)[i][j] += 1;
            }
        }
    } 
}

int main(){
    // Primeiro quero montar o tabuleiro.
    // notemos agora que usar o tabuleiro de char não é tão bom...
    // Vou montar o tabuleiro de int.
    int **matrix, lin, col;
    char lixo;
    scanf("%d%c%d", &lin, &lixo, &col);
    if (lin < 0 || col < 0){
        printf("-1\n");
        return(0);
    }
    matrix = createMatrix(lin, col);

    int nbombs, posLine, posCol, rad;
    if (nbombs < 0 || posLine < 0 || posCol < 0 || rad < 0){
        printf("-1\n");
        return(0);
    }
    scanf("%d", &nbombs);
    for (int i = 0; i < nbombs; i++){
        scanf("%d %d %d", &posLine, &posCol, &rad);
        insertingBombs(&matrix, posLine, posCol, rad, lin, col);
    }
    
    Tank *tank = createTank();
    scanf("%d %d %d", &tank->posX, &tank->posY, &tank->res);
    if (tank->posX < 0 || tank->posY < 0 || tank->res < 1){
        printf("-1\n");
        return(0);
    }
    if(matrix[tank->posX][tank->posY] >= tank-> res){
        printf("Boom\n");
    } else {
        printf("Ufa\n");
    }
    
    destroyMatrix(&matrix, lin);
    return(0);
}