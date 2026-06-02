#include <stdio.h>

/*
  FUNÇÃO: menorIndex
  OBJETIVO: Encontrar a posição (índice) do menor elemento em um vetor, 
  começando a busca a partir de uma posição específica.
  
  PARÂMETROS:
  - vet[]: O vetor de números inteiros onde vamos procurar.
  - tam: O tamanho total do vetor.
  - ini: A posição (índice) a partir da qual a busca deve começar.
*/
int menorIndex(int vet[], int tam, int ini){
    
    /* 1. O CHUTE INICIAL:
      Assumimos temporariamente que o primeiro elemento da nossa 
      área de busca (a posição 'ini') é o menor de todos.
      Guardamos apenas o ÍNDICE dele na variável 'min'.
    */
    int min = ini, j;
    
    /*
      2. A BUSCA (VARREDURA):
      O laço 'for' começa a olhar a partir da próxima "gaveta" (ini + 1)
      e vai até o final do vetor (tam). Não precisamos testar a posição 
      'ini' de novo porque ela já é o nosso chute inicial.
    */
    for(j = ini + 1; j < tam; j++){
        
        /*
          3. A COMPARAÇÃO:
          Aqui perguntamos: "O valor que eu achava que era o menor (vet[min]) 
          é MAIOR do que o valor que estou olhando agora (vet[j])?"
          
          Se for verdade, significa que acabamos de achar um número 
          ainda menor durante a nossa varredura!
        */
        if(vet[min] > vet[j]){
            
            /* Atualizamos a variável 'min' para guardar essa nova posição */
            min = j;
        }
    }
    
    /* Ao final do laço, retornamos a posição definitiva do menor valor */
    return min; 
}

int main(){
    /* CRIANDO O CENÁRIO DE TESTE:
      Temos um vetor de 5 posições. 
      Lembre-se que em C, os índices sempre vão de 0 a 4.
    */
    int meuVetor[] = {45, 12, 89, 5, 23};
    int tamanho = 5;
    
    /* CHAMANDO A FUNÇÃO:
      Pedimos para a função procurar o menor número em 'meuVetor',
      que tem 'tamanho' 5, e queremos que a busca comece do índice 0 
      (ou seja, queremos varrer o vetor inteiro desde o começo).
    */
    int posicaoDoMenor = menorIndex(meuVetor, tamanho, 0);
    
    /* EXIBINDO OS RESULTADOS:
      Usamos '%d' para imprimir os números inteiros na tela.
      Importante: 'posicaoDoMenor' guarda ONDE o número está (o índice).
      'meuVetor[posicaoDoMenor]' acessa o VALOR REAL que está lá dentro.
    */
    printf("O indice do menor numero e: %d\n", posicaoDoMenor);
    printf("O menor valor e: %d\n", meuVetor[posicaoDoMenor]);
    
    return 0;
}