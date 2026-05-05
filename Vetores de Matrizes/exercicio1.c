#include <stdio.h>

int main()
{
    int estoque[10];
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

    printf("digite a quantidade que deseja comprar:");
    scanf("%d", &quantidade);

    if (quantidade > estoque[produto])
    {
        printf("Estoque insuficiente temos apenas: %d unidades de %s \n",
             estoque[produto], nomes[produto]);
             
    }
    else
    {
        estoque[produto] = estoque[produto] - quantidade;
        printf("compra com sucesso");
    }

    printf("\n ---ESTOQUE APOS AS COMPRAS---\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s : %d unidades\n", nomes[i], estoque[i]);
    }
}