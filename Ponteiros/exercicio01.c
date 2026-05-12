#include <stdio.h>

int main(){
    int numero = 79417;
    int *ptr;

    ptr = &numero;

    printf("Valor de 'numero' usando ponteiro: %d\n", *ptr);
    printf("o valor armazenado no ponteiro: %p\n", ptr);
    printf("Endereço da variavel 'numero': %p\n", &numero);
}