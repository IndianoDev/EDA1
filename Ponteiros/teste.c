#include <stdio.h>

void trocar(float *ptr1, float *ptr2){
    float temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    float x = 3.14;
    float y = 2.71;

    printf("valores originais: x = %.2f, y = %.2f\n", x, y);

    trocar(&x, &y);
    printf("valores trocados: x = %.2f, y = %.2f\n", x, y);
    return 0;
}