#include <stdio.h>
#include <stdlib.h> // para system("pause") se necessario, mas evitamos

//declaração das funcoes que implementam cada exemplo
void exemplo_contar_caracteres(void);
void exemplo_copiar_arquivo(void);
void exemplo_funcionarios(void);

//========
// FUNCAO PRINCIPAL
// =======

int main(){
    int opcao;

    do {
        printf("\n========\n");
        printf("EXEMPLOS DE MANIPULAÇÃO DE ARQUIVOS\n");
        printf("1 - contar caracteres, espacos, tabs e newlines\n ");
        printf("2 - copiar arquivo (origem -> destino)\n");
        printf("3 - Gravar e ler dados de funcionários\n");
        printf("0 - sair\n");
        printf("Escolha uma Opcão:");
        scanf("%d", &opcao);
        getchar(); //limpa o \n deixado pelo scanf
    
    switch (opcao)    {
    case 1:
        exemplo_contar_caracteres();
        break;
    case 2:
        exemplo_copiar_arquivo();
        break;
    case 3:
        exemplo_funcionarios();
        break;
    case 0:
        printf("encerando o programa.\n");
        break;

    default:
        printf("Opcao invalida! Tente novamente.\n");
    }
    }while (opcao != 0);

    return 0;
    
    
}