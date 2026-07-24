#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

void exibirMenu() {
    printf("\n--- Analise Climatica ---\n");
    printf("1. Reset\n");
    printf("2. Inserir Medida\n");
    printf("3. Estatistica\n");
    printf("4. Sair\n");
    printf("Escolha: ");
}

int main() {
    TTemperaturas db;
    db.qtde_dias = 0;
    db.qtde_medidas = 0;
    db.medidas = NULL;

    int op = -1;

    do {
        exibirMenu();
        if (scanf("%d", &op) != 1) {
            while(getchar() != '\n');
            op = -1;
        }

        switch(op) {
            case 1:
                if (db.medidas != NULL) {
                    for(int i = 0; i < db.qtde_medidas; i++) {
                        free(db.medidas[i].temperatura);
                    }
                    free(db.medidas);
                }
                
                printf("Informe a quantidade maxima de dias: ");
                scanf("%d", &db.qtde_dias);
                db.qtde_medidas = 0;
                
                db.medidas = (TMedidas*) malloc(db.qtde_dias * sizeof(TMedidas));
                if (db.medidas == NULL) {
                    printf("Erro de memoria.\n");
                    db.qtde_dias = 0;
                } else {
                    printf("Memoria alocada com sucesso.\n");
                }
                break;
                
            case 2:
                if (db.medidas == NULL) {
                    printf("Faca o Reset primeiro para alocar memoria.\n");
                } else if (db.qtde_medidas >= db.qtde_dias) {
                    printf("O vetor ja esta cheio.\n");
                } else {
                    int p = db.qtde_medidas;
                    
                    printf("Nome da cidade: ");
                    while(getchar() != '\n'); 
                    fgets(db.medidas[p].cidade, 20, stdin);
                    db.medidas[p].cidade[strcspn(db.medidas[p].cidade, "\n")] = 0;

                    db.medidas[p].temperatura = (float*) malloc(sizeof(float));
                    
                    printf("Temperatura: ");
                    scanf("%f", db.medidas[p].temperatura);

                    db.qtde_medidas++;
                    printf("Medida registrada.\n");
                }
                break;
                
            case 3:
                if (db.qtde_medidas == 0) {
                    printf("Nenhuma medida para analisar.\n");
                } else {
                    float soma = 0;
                    float min = *db.medidas[0].temperatura;
                    float max = *db.medidas[0].temperatura;
                    int pMin = 0;
                    int pMax = 0;

                    for(int i = 0; i < db.qtde_medidas; i++) {
                        float tempAtual = *db.medidas[i].temperatura;
                        soma += tempAtual;
                        
                        if (tempAtual < min) {
                            min = tempAtual;
                            pMin = i;
                        }
                        if (tempAtual > max) {
                            max = tempAtual;
                            pMax = i;
                        }
                    }
                    
                    printf("\n--- Resultados ---\n");
                    printf("Media de temperatura: %.2f\n", soma / db.qtde_medidas);
                    printf("Menor temperatura: %.2f em %s\n", min, db.medidas[pMin].cidade);
                    printf("Maior temperatura: %.2f em %s\n", max, db.medidas[pMax].cidade);
                }
                break;
                
            case 4:
                if (db.medidas != NULL) {
                    for(int i = 0; i < db.qtde_medidas; i++) {
                        free(db.medidas[i].temperatura);
                    }
                    free(db.medidas);
                    db.medidas = NULL;
                }
                printf("Memoria liberada com sucesso. Encerrando...\n");
                break;
                
            default:
                printf("Opcao invalida.\n");
        }
    } while (op != 4);

    return 0;
}