#include <stdio.h>

/*
  FUNÇÃO: bubbleSort (Ordenação por Bolha)
  A brincadeira: O inspetor de fila trocando os vizinhos de lugar.
*/
void bubbleSort(int vetor[], int tamanho) {
    int parede, inspetor, temp;

    /* 1. A PAREDE (Trancando os números no final):
       A variável 'parede' (no slide era o 'i') começa lá no final (tamanho - 1) 
       e vem encolhendo para a esquerda (parede--). 
       Tudo que estiver da parede para frente já está ordenado!
    */
    for (parede = tamanho - 1; parede > 0; parede--) {
        
        /* 2. O INSPETOR (Andando do começo até a parede):
           O 'inspetor' (no slide era o 'j') começa no índice 0 e vai 
           andando de vizinho em vizinho até bater na 'parede'.
        */
        for (inspetor = 0; inspetor < parede; inspetor++) {
            
            /* 3. A COMPARAÇÃO DE VIZINHOS:
               O inspetor olha para a carta atual e para a carta da direita.
               Se a carta da esquerda for MAIOR, elas estão no lugar errado!
            */
            if (vetor[inspetor] > vetor[inspetor + 1]) {
                
                /* 4. A TROCA (Swap):
                   Usa o "copo vazio" (temp) para trocar as cartas de mão.
                */
                temp = vetor[inspetor];
                vetor[inspetor] = vetor[inspetor + 1];
                vetor[inspetor + 1] = temp;
            }
        }
    }
}

/* Função auxiliar para você ver a mágica rodando */
void imprimeVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int cartas[] = {5, 3, 4, 1};
    int totalCartas = 4;

    printf("Cartas baguncadas na mesa:\n");
    imprimeVetor(cartas, totalCartas);

    // Chamando o nosso Inspetor Bolha
    bubbleSort(cartas, totalCartas);

    printf("\nCartas arrumadas:\n");
    imprimeVetor(cartas, totalCartas);
    

    return 0;
}