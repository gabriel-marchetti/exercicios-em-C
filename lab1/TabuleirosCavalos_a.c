# include <stdio.h>
# include <stdlib.h>

int main()
{
    char posHor, abcCheck[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int posVert, posHorConv, numCheck[] = {1, 2, 3, 4, 5, 6, 7, 8};

    scanf("%c %d", &posHor, &posVert);
    posHorConv = (int)posHor; // extrai valor da ASCII
    posHorConv -= 65; // Usa valor da ASCII entre 0 a 8
    posVert -= 1;

    
    if (posVert < 0 || posVert > 8 || posHorConv < 0 || posHorConv > 8 )
    {
        printf("Inválido.\n");
        exit(1);
    }

    for (int i = 0; i < 8; i++)
    { 
        int auxVert;
        char auxHor;

        switch (i)
        {
        case 0:
            if (posVert + 2 < 0 || posVert + 2 > 7 || posHorConv - 1 < 0 || posHorConv - 1 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv - 1];
            auxVert = numCheck[posVert + 2];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 1:
            if (posVert + 2 < 0 || posVert + 2 > 7 || posHorConv + 1 < 0 || posHorConv + 1 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv + 1];
            auxVert = numCheck[posVert + 2];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 2:
            if (posVert + 1 < 0 || posVert + 1 > 7 || posHorConv + 2 < 0 || posHorConv + 2 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv + 2];
            auxVert = numCheck[posVert + 1];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 3:
            if (posVert - 1 < 0 || posVert - 1 > 7 || posHorConv + 2 < 0 || posHorConv + 2 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv + 2];
            auxVert = numCheck[posVert - 1];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 4:
            if (posVert - 2 < 0 || posVert - 2 > 7 || posHorConv + 1 < 0 || posHorConv + 1 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv + 1];
            auxVert = numCheck[posVert - 2];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 5:
            if (posVert - 2 < 0 || posVert - 2 > 7 || posHorConv - 1 < 0 || posHorConv - 1 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv - 1];
            auxVert = numCheck[posVert - 2];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 6:
            if (posVert - 1 < 0 || posVert - 1 > 7 || posHorConv - 2 < 0 || posHorConv - 2 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv - 2];
            auxVert = numCheck[posVert - 1];
            printf("%c %d\n", auxHor, auxVert);
            break;
        case 7:
            if (posVert + 1 < 0 || posVert + 1 > 7 || posHorConv - 2 < 0 || posHorConv - 2 > 7 )
            {
                break;
            }
            auxHor = abcCheck[posHorConv - 2];
            auxVert = numCheck[posVert + 1];
            printf("%c %d\n", auxHor, auxVert);
            break;
        default:
            continue;
        }

    }

    return(0);
}