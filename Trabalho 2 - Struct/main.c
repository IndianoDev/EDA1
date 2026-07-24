#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CadastroU {
    char CNPJ[20];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo;
} TCadastroU;

typedef struct NoU {
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

typedef struct DescritorU {
    TNoU *Inicio;
    int Tamanho;
    TNoU *Fim;
} TDescritorU;

void inicializaLista(TDescritorU* desc);
void insereFim(TDescritorU* desc, TCadastroU* cadastro);
void carregaArquivos(TDescritorU* desc);
void lerArquivoParaLista(TDescritorU* desc, const char* nomeArquivo, char tipo);
void relatorio(TDescritorU* desc, char filtroTipo, int invertido);
void liberaMemoria(TDescritorU* desc);
void exibirMenu();

int main() {
    TDescritorU lista;
    inicializaLista(&lista);
    int op = -1;

    do {
        exibirMenu();
        if (scanf("%d", &op) != 1) {
            while(getchar() != '\n');
            op = -1;
        }
        printf("\n");

        switch (op) {
            case 1:
                carregaArquivos(&lista);
                break;
            case 2:
                printf("Lista unificada ja foi gerada.\n");
                break;
            case 3:
                relatorio(&lista, 'I', 0);
                break;
            case 4:
                relatorio(&lista, 'C', 0);
                break;
            case 5:
                relatorio(&lista, 'C', 1);
                break;
            case 6:
                relatorio(&lista, 'S', 0);
                break;
            case 7:
                relatorio(&lista, 'S', 1);
                break;
            case 8:
                relatorio(&lista, 'T', 0);
                break;
            case 9:
                relatorio(&lista, 'T', 1);
                break;
            case 10:
                liberaMemoria(&lista);
                break;
            case 0:
                liberaMemoria(&lista);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}

void exibirMenu() {
    printf("\n--- Sefaz DF ---\n");
    printf("1. Carregar Dados de Entrada\n");
    printf("2. Gerar Lista Unificada\n");
    printf("3. Relatorio: Industrias\n");
    printf("4. Relatorio: Comercio\n");
    printf("5. Relatorio: Comercio Invertida\n");
    printf("6. Relatorio: Servicos\n");
    printf("7. Relatorio: Servicos Invertida\n");
    printf("8. Relatorio: Lista Unificada\n");
    printf("9. Relatorio: Lista Unificada Invertida\n");
    printf("10. Apagar Listas\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

void inicializaLista(TDescritorU* desc) {
    desc->Inicio = NULL;
    desc->Fim = NULL;
    desc->Tamanho = 0;
}

void insereFim(TDescritorU* desc, TCadastroU* cadastro) {
    TNoU* novo = (TNoU*)malloc(sizeof(TNoU));
    if (!novo) return;

    novo->Dados = cadastro;
    novo->Prox = NULL;
    novo->Ant = desc->Fim;

    if (desc->Tamanho == 0) {
        desc->Inicio = novo;
    } else {
        desc->Fim->Prox = novo;
    }

    desc->Fim = novo;
    desc->Tamanho++;
}

void carregaArquivos(TDescritorU* desc) {
    if (desc->Tamanho > 0) {
        printf("Dados ja carregados.\n");
        return;
    }
    
    lerArquivoParaLista(desc, "Industria.txt", 'I');
    lerArquivoParaLista(desc, "Comercio.txt", 'C');
    lerArquivoParaLista(desc, "Servico.txt", 'S');
    
    printf("Arquivos carregados. Total: %d registros.\n", desc->Tamanho);
}

void lerArquivoParaLista(TDescritorU* desc, const char* nomeArquivo, char tipo) {
    FILE* arq = fopen(nomeArquivo, "r");
    if (!arq) {
        printf("Erro ao abrir %s\n", nomeArquivo);
        return;
    }

    char linha[150];
    
    while (fgets(linha, sizeof(linha), arq)) {
        linha[strcspn(linha, "\r\n")] = 0;
        char* tok = strtok(linha, ";");
        
        if (tok) {
            TCadastroU* cad = (TCadastroU*)malloc(sizeof(TCadastroU));
            strcpy(cad->CNPJ, tok);
            
            tok = strtok(NULL, ";");
            if (tok) {
                strcpy(cad->RazaoSocial, tok);
                strcpy(cad->Cidade, "N/A");
                strcpy(cad->Fone, "N/A");
                cad->Tipo = tipo;
                
                insereFim(desc, cad);
            } else {
                free(cad);
            }
        }
    }
    fclose(arq);
}

void relatorio(TDescritorU* desc, char filtroTipo, int invertido) {
    if (desc->Tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    TNoU* atual = invertido ? desc->Fim : desc->Inicio;
    int cont = 0;

    printf("\n--- Relatorio ---\n");
    while (atual) {
        if (filtroTipo == 'T' || atual->Dados->Tipo == filtroTipo) {
            printf("[%c] CNPJ: %s | Empresa: %s\n", 
                   atual->Dados->Tipo, atual->Dados->CNPJ, atual->Dados->RazaoSocial);
            cont++;
        }
        atual = invertido ? atual->Ant : atual->Prox;
    }
    printf("Total listado: %d\n", cont);
}

void liberaMemoria(TDescritorU* desc) {
    if (desc->Tamanho == 0) return;

    TNoU* atual = desc->Inicio;
    while (atual) {
        TNoU* aux = atual;
        atual = atual->Prox;
        
        if (aux->Dados) free(aux->Dados);
        free(aux); 
    }
    
    desc->Inicio = NULL;
    desc->Fim = NULL;
    desc->Tamanho = 0;
    
    printf("Memoria liberada.\n");
}