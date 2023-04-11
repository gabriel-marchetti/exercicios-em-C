# include <stdio.h>
# include <stdlib.h>

int converteHor(char posHor)
{
    int posHorConv;
    posHorConv = (int)posHor; // extrai valor da ASCII
    posHorConv -= 65; // Usa valor da ASCII entre 0 a 8

    return(posHorConv);
}

int** criaMatriz(int nlin, int ncol)
{
    int** matriz;
    matriz = (int **)calloc(nlin, sizeof(int *));

    for (int linha = 0; linha < nlin; linha++)
    {
        matriz[linha] = (int *)calloc(ncol, sizeof(int));
    }

    return(matriz);
}

void destroiMatriz(int*** matriz, int nlin)
{
    if ( (*matriz) != NULL)
    {
        for (int i = 0; i < nlin; i++)
        {
            free((*matriz)[i]);
        }
        free(*matriz);
        *matriz = NULL;
    }
}

int main()
{
    int n, posVert, posHorConv;
    char posHor;
    int** matriz;

    matriz = criaMatriz(8, 8);

    scanf("%d", &n);

    int i = 0;
    while (i < n)
    {
        scanf(" %c %d", &posHor, &posVert);
        posHorConv = converteHor(posHor);
        posVert -= 1; // Lista comeca em 0

        if ( matriz[posVert][posHorConv] != 0)
        {
            printf("Invalido\n");
        }
        else
        {
            matriz[posVert][posHorConv] = 1;
        }
        

        i++;
    }

    for (int posVert = 0; posVert < 8; posVert++)
    {
        for (int posHor = 0; posHor < 8; posHor++)
        {
            if ( matriz[posVert][posHor] == 1 )
            {
                
                for (int iter = 0; iter < 8; iter++)
                {   
                    switch (iter)
                    {
                    case 0:
                        if (posVert + 2 < 0 || posVert + 2 > 7 || posHorConv - 1 < 0 || posHorConv - 1 > 7)
                        {
                            break;
                        }
                        
                        if ( matriz[posVert + 2][posHorConv - 1] == 1 )
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 1:
                        if (posVert + 2 < 0 || posVert + 2 > 7 || posHorConv + 1 < 0 || posHorConv + 1 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert + 2][posHorConv +1] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 2:
                        if (posVert + 1 < 0 || posVert + 1 > 7 || posHorConv + 2 < 0 || posHorConv + 2 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert + 1][posHorConv + 2] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 3:
                        if (posVert - 1 < 0 || posVert - 1 > 7 || posHorConv + 2 < 0 || posHorConv + 2 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert - 1][posHorConv + 2] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 4:
                        if (posVert - 2 < 0 || posVert - 2 > 7 || posHorConv + 1 < 0 || posHorConv + 1 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert - 2][posHorConv + 1] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 5:
                        if (posVert - 2 < 0 || posVert - 2 > 7 || posHorConv - 1 < 0 || posHorConv - 1 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert - 2][posHorConv - 1] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 6:
                        if (posVert - 1 < 0 || posVert - 1 > 7 || posHorConv - 2 < 0 || posHorConv - 2 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert - 1][posHorConv - 2] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    case 7:
                        if (posVert + 1 < 0 || posVert + 1 > 7 || posHorConv - 2 < 0 || posHorConv - 2 > 7 )
                        {
                            break;
                        }
                        
                        if (matriz[posVert + 1][posHorConv - 2] == 1)
                        {
                            printf("Os cavalos estao em guerra!\n");
                            exit(1);
                        }

                        break;
                    default:
                        continue;
                    }
                }
            }
        }
    }

    printf("Paz no reino!\n");
    
    destroiMatriz(&matriz, 8);

    return(0);
}