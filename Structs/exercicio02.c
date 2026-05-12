#include <stdio.h>
#include <string.h> //esssa biblioteca aqui mano vei é pra usar o strcpy 
// strcpy esse que é pra atribuir texto para uma string em C.


struct Pessoa{
    char nome[50];
    int idade;
    float altura;
};

int main(){
    struct Pessoa p1;

    strcpy(p1.nome, "Juan");
    p1.idade = 22;
    p1.altura = 1.75;

    p1.idade = 26;
    p1.altura = 1.81;


    printf("O novo nome da pessoa e: %s\n", p1.nome);
    printf("A nova idade da pessoa e: %d\n", p1.idade);
    printf("a nova altura da pessoa e: %.2f\n", p1.altura);
}