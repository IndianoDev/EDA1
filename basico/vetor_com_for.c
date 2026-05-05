#include <stdio.h>

int main(){
    int numeros[5];

    for (int i = 0; i < 5; i++){
        printf("digite o numero para a pocição %d: ", i );
        scanf("%d", &numeros[i]);
    }
    printf("assim seus novos valores do vetor vai ser:\n");
    for (int i = 0; i < 5; i++){
        printf("posicao %d = %d\n", i , numeros[i]);

    }
    return 0;
}