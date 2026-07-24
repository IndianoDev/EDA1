#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==========================================
// RESPOSTA DA QUESTÃO 3 - ESTRUTURA BÁSICA
// ==========================================

// 8. Definição da estrutura TNoBin
typedef struct TNoBin {
    int chave;
    struct TNoBin *esq;
    struct TNoBin *dir;
} TNoBin;

// 9. Função para criar um novo nó
TNoBin* criarNo(int valor) {
    TNoBin *novo = (TNoBin*)malloc(sizeof(TNoBin));
    if (novo != NULL) {
        novo->chave = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// 10. Função recursiva para inserção
TNoBin* inserir(TNoBin *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->chave) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->chave) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

// 11. Função de busca retornando o ponteiro
TNoBin* buscar(TNoBin *raiz, int valor) {
    if (raiz == NULL || raiz->chave == valor) {
        return raiz;
    }
    if (valor < raiz->chave) {
        return buscar(raiz->esq, valor);
    }
    return buscar(raiz->dir, valor);
}

// ==========================================
// RESPOSTA DA QUESTÃO 4 - INVENTÁRIO (CASO PRÁTICO)
// ==========================================

// Estrutura do nó do inventário
typedef struct NoInventario {
    int codigo;
    char nome[50];
    struct NoInventario *esq;
    struct NoInventario *dir;
} NoInventario;

NoInventario* criarNoInv(int cod, char* desc) {
    NoInventario *novo = (NoInventario*)malloc(sizeof(NoInventario));
    novo->codigo = cod;
    strcpy(novo->nome, desc);
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

NoInventario* inserirInv(NoInventario *raiz, int cod, char* desc) {
    if (raiz == NULL) return criarNoInv(cod, desc);
    
    if (cod < raiz->codigo) {
        raiz->esq = inserirInv(raiz->esq, cod, desc);
    } else if (cod > raiz->codigo) {
        raiz->dir = inserirInv(raiz->dir, cod, desc);
    }
    return raiz;
}

// Função solicitada na questão 4
char* buscarEquipamento(NoInventario *raiz, int cod_busca) {
    if (raiz == NULL) {
        return "Nao encontrado";
    }
    if (raiz->codigo == cod_busca) {
        return raiz->nome;
    }
    if (cod_busca < raiz->codigo) {
        return buscarEquipamento(raiz->esq, cod_busca);
    }
    return buscarEquipamento(raiz->dir, cod_busca);
}

// Função para limpar a memória do inventário e evitar Memory Leaks
void liberarArvoreInv(NoInventario *raiz) {
    if (raiz != NULL) {
        liberarArvoreInv(raiz->esq);
        liberarArvoreInv(raiz->dir);
        free(raiz);
    }
}

// ==========================================
// MAIN (PARA TESTES E GERAÇÃO DE LOGS)
// ==========================================
int main() {
    printf("--- TESTE DO INVENTARIO DO LABORATORIO (Q4) ---\n\n");
    NoInventario *raiz_inv = NULL;
    
    // Inserindo equipamentos
    raiz_inv = inserirInv(raiz_inv, 1050, "Osciloscopio Digital");
    raiz_inv = inserirInv(raiz_inv, 1020, "Multimetro Bancada");
    raiz_inv = inserirInv(raiz_inv, 1080, "Fonte de Tensao");
    raiz_inv = inserirInv(raiz_inv, 1010, "Estacao de Solda");
    
    // Testando as buscas
    int buscas[] = {1050, 1010, 9999};
    
    for (int i = 0; i < 3; i++) {
        printf("Buscando Patrimonio [%d]...\n", buscas[i]);
        char* resultado = buscarEquipamento(raiz_inv, buscas[i]);
        printf("Resultado: %s\n\n", resultado);
    }

    liberarArvoreInv(raiz_inv);
    printf("Memoria liberada com sucesso. Fim do programa.\n");
    return 0;
}