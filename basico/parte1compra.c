#include <stdio.h>

int main()
{
    int estoque[100];
    int i;
    int produto, quantidade;
    char nomes[10][20] = {
        "Arroz", "Feijao", "Macarrao", "Acucar", "Sal",
        "Oleo", "Farinha", "Cafe", "Leite", "Sabao"};
    for (i = 0; i < 10; i++)
    {
        printf("digite a quantidade de %s: ", nomes[i]);
        scanf("%d", &estoque[i]);
    }
    printf("\n----ESTOQUE ATUAL----\n");
    for (i = 0; i < 10; i++)
    {
        printf("%s: %d unidades\n", nomes[i], estoque[i]);
    }

    printf("\n ---COMPRAR PRODUTO---\n");
    printf("digite um numero entre 0 e 9:");
    scanf("%d", &produto);

    printf("digite a quantidade que deseja comprar:" );
    scanf("%d", &quantidade);

    estoque[produto] = estoque[produto] - quantidade;

    printf("\n ---ESTOQUE APOS AS COMPRAS---\n");
    for (int i = 0; i < 10; i ++) {
        printf("%s : %d unidades\n", nomes[i], estoque[i]);
    }
}