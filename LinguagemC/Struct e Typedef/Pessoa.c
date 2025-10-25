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

#include <stdio.h>
#include <string.h> // Necessário para usar a função strcpy

// 1. Definição da Struct
// Uma 'struct' é um tipo de dado definido pelo usuário que agrupa variáveis
// de diferentes tipos sob um único nome.
struct Aluno {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

// Protótipo da função para calcular a média
void calcularMedia(struct Aluno *a);

int main() {
    // 2. Declaração e Inicialização de uma Variável Struct
    struct Aluno aluno1;

    // 3. Atribuição de Valores aos Membros da Struct
    aluno1.matricula = 102345;

    // Use strcpy para copiar strings (vetores de char)
    // Não se pode usar aluno1.nome = "João da Silva"; diretamente.
    strcpy(aluno1.nome, "João da Silva");

    aluno1.nota1 = 7.5;
    aluno1.nota2 = 8.2;

    // 4. Chamada de função que manipula a Struct
    // Passamos o endereço de aluno1 para a função
    calcularMedia(&aluno1);

    // 5. Exibição dos Dados da Struct
    printf("\n--- Ficha do Aluno ---\n");
    printf("Matrícula: %d\n", aluno1.matricula);
    printf("Nome: %s\n", aluno1.nome);
    printf("Nota 1: %.2f\n", aluno1.nota1);
    printf("Nota 2: %.2f\n", aluno1.nota2);
    printf("Média Final: %.2f\n", aluno1.media);

    return 0;
}

// 6. Implementação da Função
// A função recebe um ponteiro para a struct (*a) para poder modificar
// diretamente os valores da struct original (a 'aluno1' na main).
void calcularMedia(struct Aluno *a) {
    // O operador '->' (seta) é usado para acessar membros de uma struct
    // quando se tem um PONTEIRO para ela. É o mesmo que (*a).media.
    a->media = (a->nota1 + a->nota2) / 2.0;
}
