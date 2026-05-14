#include <stdio.h>

int main(){
    int numero = 79417;
    int *ptr; //declaração de um ponteiro para int

    //Atribuição do endereço de "numero " ao ponteiro ptr:
    ptr = &numero;

    //Impressão do endereço de "numero"
    //e seu valor usando o ponteiro
    printf("o valor do endereço do 'numero' e: %p\n", &numero);
    printf("o endereço do ponteiro e: %p\n", ptr);
    printf("o valor do 'numero ' e: %d\n ", *ptr);
    return 0;
}

