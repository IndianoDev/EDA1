
#include  <stdio.h>

struct Livro{
    char titulo[100];
    char autor[50];
    int ano_de_publicacao; 
    int numero_de_pagina;
};

int main(){
    struct Livro l1, l2;

    printf("Digite o titulo da livro 1: ");
    scanf("%s", l1.titulo);

    printf("digite o nome do Autor do Livro 2");
    scanf("%s", l1.autor);

}