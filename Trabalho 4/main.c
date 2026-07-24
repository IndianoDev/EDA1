#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int ibge;
    int linha;
} Indice;

void carregar(Indice **v, int *tam);
void consultar(Indice *v, int tam);
void limpar(Indice **v);

int main() {
    Indice *vet = NULL;
    int tam = 0;
    int op;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Carregar dados\n");
        printf("2. Consultar municipio\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                carregar(&vet, &tam);
                break;
            case 2:
                consultar(vet, tam);
                break;
            case 3:
                limpar(&vet);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while(op != 3);

    return 0;
}

void carregar(Indice **v, int *tam) {
    limpar(v);
    *tam = 0;

    FILE *arq = fopen("EDA_Trabalho_4_Algoritmo_de_Busca_Workbook.csv", "r");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    char lin[512];
    fgets(lin, sizeof(lin), arq);

    while (fgets(lin, sizeof(lin), arq) != NULL) {
        *v = (Indice *) realloc(*v, (*tam + 1) * sizeof(Indice));
        
        char *tok = strtok(lin, ",");
        if (tok != NULL) (*v)[*tam].ibge = atoi(tok);

        tok = strtok(NULL, ",");
        if (tok != NULL) (*v)[*tam].linha = atoi(tok);

        (*tam)++;
    }

    fclose(arq);
    printf("Dados carregados! %d registros\n", *tam);
}

void consultar(Indice *v, int tam) {
    if (v == NULL || tam == 0) {
        printf("Carregue os dados primeiro\n");
        return;
    }

    int busca;
    printf("Digite o IBGE: ");
    scanf("%d", &busca);
    getchar();

    clock_t t1 = clock();
    int p_seq = -1;
    for (int i = 0; i < tam; i++) {
        if (v[i].ibge == busca) {
            p_seq = i;
            break;
        }
    }
    clock_t t2 = clock();
    double tempo_seq = (double)(t2 - t1) / CLOCKS_PER_SEC;

    clock_t t3 = clock();
    int p_bin = -1;
    int esq = 0, dir = tam - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (v[meio].ibge == busca) {
            p_bin = meio;
            break;
        } else if (v[meio].ibge < busca) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    clock_t t4 = clock();
    double tempo_bin = (double)(t4 - t3) / CLOCKS_PER_SEC;

    if (p_bin == -1) {
        printf("IBGE nao encontrado\n");
        return;
    }

    int linha_alvo = v[p_bin].linha;
    
    FILE *arq = fopen("EDA_Trabalho_4_Algoritmo_de_Busca_Workbook.csv", "r");
    char lin[512];
    fgets(lin, sizeof(lin), arq);

    for (int i = 0; i < linha_alvo; i++) {
        fgets(lin, sizeof(lin), arq);
    }
    fclose(arq);

    strtok(lin, ",");
    strtok(NULL, ",");
    char *mun = strtok(NULL, ",");
    char *uf = strtok(NULL, ",");
    char *reg = strtok(NULL, ",");
    char *pop = strtok(NULL, ",");
    char *porte = strtok(NULL, "\r\n");

    printf("\nMunicipio: %s\n", mun);
    printf("UF: %s\n", uf);
    printf("Regiao: %s\n", reg);
    printf("Populacao: %s\n", pop);
    printf("Porte: %s\n", porte);

    printf("\nTempo Sequencial: %f s\n", tempo_seq);
    printf("Tempo Binaria: %f s\n", tempo_bin);
}

void limpar(Indice **v) {
    if (*v != NULL) {
        free(*v);
        *v = NULL;
    }
}