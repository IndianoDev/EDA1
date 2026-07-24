#include <stdio.h>

int main(){
    int a = 10;
    float b = 5.5;

    int *p_a = &a;
    int *p_b = &b;

    printf("Variavel inteira: valor = %d, endereco = %p\n", *p_a, p_a);
    printf("Variavel float: valor = %.2f, endereco = %p\n", *p_b, p_b);

    return 0;
}