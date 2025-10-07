//Struct
#include <stdio.h>
#include <string.h>

int main() {
    struct Pessoa{
        char nome[50];
        int idade;
        float altura;
    };
    
    struct Pessoa p;
    
    strcpy(p.nome, "Teuszin"); 
    p.idade = 18;
    p.altura = 1.63;

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);        
    printf("Altura: %.2f\n", p.altura);
    
    return 0;
}

//Typedef

#include <stdio.h>
#include <string.h>

int main() {
    typedef struct{
        char nome[50];
        int idade;
        float altura;
    }Pessoa;
    
    Pessoa p;
    
    strcpy(p.nome, "Teuszin"); 
    p.idade = 18;
    p.altura = 1.63;

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);        
    printf("Altura: %.2f\n", p.altura);
    
    return 0;
}
