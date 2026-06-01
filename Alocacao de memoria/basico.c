#include <stdio.h>
#include <stdlib.h>

struct x {
    int a; //4 bites
    double b; 
    int c;
};

int main (void){

    struct x estrutura;
    int vetor [10];
    int x; // armazerna 4 bytes
    double y; //pode armazenar um numero de 8 bytes(64 bits)

    printf("%li", sizeof(estrutura));//tamanho do parameto sizeof (tamanho de...)

    return 0;

}