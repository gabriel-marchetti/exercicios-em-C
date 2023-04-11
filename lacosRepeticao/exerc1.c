# include <stdio.h>
# include <math.h>
# include <stdbool.h>

int main()
{
    bool status = true;
    int pedido;

    printf("1 - Pizza de Marguerita\n"
            "2 - Pizza de Peperoni\n"
            "3 - Pizza de Calabresa\n"
            "4 - Pizza de Mussarela\n"
            "5 - Sair\n");

    printf("------------------\n");
    printf("O que deseja pedir: ");

    scanf("%d", &pedido);

    while (status == true)
    {
        switch (pedido)
        {
        case 1:
            printf("Pizza de Marguerita Servida!\n");
            printf("Deseja mais alguma coisa: ");
            scanf("%d", &pedido);
            break;
        case 2:
            printf("Pizza de Peperoni Servida!\n");
            printf("Deseja mais alguma coisa: ");
            scanf("%d", &pedido);
            break;
        case 3:
            printf("Pizza de Calabresa Servida!\n");
            printf("Deseja mais alguma coisa: ");
            scanf("%d", &pedido);
            break;
        case 4:
            printf("Pizza de Mussarela Servida!\n");
            printf("Deseja mais alguma coisa: ");
            scanf("%d", &pedido);
            break;    
        default:
            status = false;
            break;
        }
    }

    return(0);
}