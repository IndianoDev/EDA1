#include <stdio.h>

/*
  FUNÇÃO: separa (Particionamento de Lomuto do Quick Sort)
  OBJETIVO: Escolhe um pivô e organiza o vetor de forma que:
  - Todos os números menores ou iguais ao pivô fiquem à sua esquerda.
  - Todos os números maiores fiquem à sua direita.
*/
int separa(int v[], int p, int r) {
    
    /* 1. O PIVÔ:
       A nossa "régua". Neste método, sempre escolhemos o último 
       elemento do trecho atual do vetor (posição 'r').
    */
    int c = v[r]; 
    
    /* Variável 't' será o nosso "copo vazio" para fazer as troca s (swap) */
    int t;        
    
    /* 2. A PAREDE IMAGINÁRIA:
       A variável 'j' marca onde termina a área dos "menores que o pivô".
       Ela começa encostada lá no início (posição 'p').
    */
    int j = p;    

    /* 3. A VARREDURA (O Explorador):
       O explorador 'k' vai do início (p) até o penúltimo elemento (r - 1).
       Ele não vai até 'r' porque lá está o nosso pivô quietinho.
    */
    for (int k = p; k < r; ++k) {
        
        /* O explorador pergunta: "O número atual é menor ou igual ao pivô?" */
        if (v[k] <= c) {
            
            /* Se SIM, esse número precisa ir para o lado esquerdo da parede!
               Então, trocamos o número que o explorador achou (v[k]) 
               com o número que está logo ali na parede (v[j]).
            */
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            
            /* E agora a parede dá um passo para frente, pois a área 
               dos números pequenos acabou de crescer.
            */
            ++j;
        }
    }

    /* 4. O TOQUE FINAL:
       O explorador terminou. A parede 'j' está exatamente no meio,
       separando os pequenos dos grandes. Onde colocamos o pivô?
       Bem na posição da parede (j)! Trocamos o pivô que estava 
       escondido lá no final (v[r]) com o número que está na parede.
    */
    t = v[j];
    v[j] = v[r];
    v[r] = t;

    /* Retornamos o índice 'j', que é o local definitivo do pivô! */
    return j;
}

/* Função auxiliar rápida apenas para mostrar o vetor na tela
  e te ajudar a estudar a mudança.
*/
void imprimeVetor(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    /* CRIANDO O CENÁRIO DE TESTE:
       Vamos usar um vetor onde o ÚLTIMO número (10) será o pivô.
    */
    int vetor[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = 7;

    printf("Vetor ANTES do particionamento:\n");
    imprimeVetor(vetor, tamanho);

    /* CHAMANDO A FUNÇÃO 'separa':
      Mandamos o vetor, a primeira posição (0) e a última posição (6).
      Lembrando que tamanho é 7, então a última posição é 7 - 1.
    */
    int posicaoPivo = separa(vetor, 0, tamanho - 1);

    printf("\nVetor DEPOIS do particionamento:\n");
    imprimeVetor(vetor, tamanho);
    
    printf("\nO pivo (10) encontrou o seu lugar definitivo no indice: %d\n", posicaoPivo);

    return 0;
}