
#include <stdio.h>

struct produto
{
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    struct produto p1;

    p1.quantidade = 10;
    p1.preco = 5.99;

    printf("quantidade: %d\n", p1.quantidade);
    printf("preco: %.2f\n", p1.preco);

    return 0;
}
