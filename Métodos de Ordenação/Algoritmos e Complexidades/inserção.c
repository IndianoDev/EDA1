#include <stdio.h>

/*
Função: insertioSort (ordenação por inserção)
a brincadeira do bralhp: arrumar as cartas na mao uma por uma.
*/

void insertionSort(int vetor[], int tamanho){
    int i, j;
    int cartaAtual; // no slide do professor, essa variavel se chama next

    /* 1. PEGANDO AS CARTAS DA MESA;
    o lado começa em "i = 1" (a segunda carta).
    por que não começa no 0? porque se voce tem so 1 carta na mao(a carta 0), ela ja esta arrumada por padrão
    */
    for (i = 1; i < tamanho; i++){
        // Você pega a carta de vez na msesa e segura ela no ar(cartaAtual)
        cartaAtual = vetor[i];

        /*2. ABIRNCO CAMINHO NA MAO ESQUERDA(O empurrão);
        a variavel 'j' vai olhar para as cartas que ja estão arrumadas,
        começando da carta logo atrás da que você pegou ( i - 1 ) e andando para trás (j--) atá chegar no inicio (j >=0).
        
        a pergunta:  'a carta que eu estou segurando (cartaAtual) é MENOR que a carta 
        que estou olhando agora (vetor[j])?'
        */
       for (j = i - 1; j>= 0 && cartaAtual < vetor[j]; j--){

        /* se for menor, a gente empurra a carta grande um espaço para a direita para abrir o "buraco"
            
        
        */
       vetor[j + 1] = vetor[j];
       }
       /* 3. INSERINDO NO BURACO:
           Quando o laço de cima termina (ou porque chegamos no fim da mão, 
           ou porque achamos uma carta menor), o buraco perfeito foi encontrado!
           Nós colocamos a nossa 'cartaAtual' nesse espaço (j + 1).
        */
        vetor[j + 1] = cartaAtual;
    
    }
}

/* Função auxiliar só para desenhar o vetor na tela do VS Code */
void imprimeVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    /* Exatamente as mesmas 4 cartas do nosso exemplo prático! */
    int cartas[] = {4, 2, 5, 1};
    int totalCartas = 4;

    printf("Cartas baguncadas na mesa:\n");
    imprimeVetor(cartas, totalCartas);

    // Chamamos a função para organizar a nossa "mão"
    insertionSort(cartas, totalCartas);

    printf("\nCartas arrumadas na mao:\n");
    imprimeVetor(cartas, totalCartas);

    return 0;
}