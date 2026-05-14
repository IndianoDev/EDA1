#include <stdio.h>

int main(){
    FILE *fp;
    int ch;
    int caracteres = 0, espacos = 0, tabs = 0, newlines = 0;
    char nomeArquivo[100];


    printf("digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    fp = fopen(nomeArquivo, "r"); // abrir o arquivo no modo leitura "r"
    if (fp == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF){ // ler caractere por caractere ate o fim EOF
        caracteres++;
        if (ch == ' ') espacos++;
        else if (ch == '\t') tabs++;
        else if (ch == '\n') newlines++;
    }
    
    fclose(fp);
    printf("\nTotal de caracteres: %d\n",caracteres);
    printf("Espacos: %d\n", espacos);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
        
    return 0;


} 