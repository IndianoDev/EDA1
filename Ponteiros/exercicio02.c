// exercicio 02
// Implementar uma função que troca os valores de duas vaariaveis usando ponteiros.

// tenho que pegar duas variaveis x e y com valores diferentes, depois chamar
// a funcao a e passa o valor de y e y ter o valor de x

#include <stdio.h>
//void significa que a funcao não retorna nenhum valor

void trocar(float *ptr1, float *ptr2){
    float temp = *ptr1; //Armazena o valor de ptr em uma variavel aleatoria
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main()
{
    float y = 2.71;
    float x = 3.14;
    printf("valores originais: x = %.2f, y = %.2f\n", x, y);
//chama a funcao criada que troca os valores das variaveis
    trocar(&x, &y);
    printf("Agora os valores trocados: x = %.2f, y = %.2f\n", x, y);

    return 0;
}