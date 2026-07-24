#include <stdio.h>

int main() {
    int A = 10, B = 20;
    int *p1 = &A;
    int *p2 = &B;

    printf("Antes: p1 aponta para %d, p2 aponta para %d\n", *p1, *p2);

    
    int *aux = p1;
    p1 = p2;
    p2 = aux;

    printf("Depois: p1 aponta para %d, p2 aponta para %d\n", *p1, *p2);
    

    return 0;
}