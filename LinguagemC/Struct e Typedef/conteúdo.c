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

#include <stdio.h>
#include <string.h>

// 1. DEFINIÇÃO DA ESTRUTURA SEM TYPEDEF
struct AlunoAntigo {
    char nome[50];
    int matricula;
    float media;
};

// 2. DEFINIÇÃO DA ESTRUTURA COM TYPEDEF
// O 'typedef' cria o alias 'Aluno' para 'struct AlunoNovo'
typedef struct AlunoNovo {
    char nome[50];
    int matricula;
    float media;
} Aluno; // <- Este é o novo nome do tipo

// 3. TYPEDEF PARA TIPOS PRIMITIVOS (para melhorar a legibilidade/portabilidade)
typedef int Inteiro;
typedef float Nota;


int main() {
    // ---------------------------------------------
    // Demonstração do uso da estrutura SEM typedef
    // ---------------------------------------------
    // Obrigatório usar a palavra 'struct'
    struct AlunoAntigo a1;
    strcpy(a1.nome, "Maria Silva");
    a1.matricula = 1001;
    a1.media = 9.5;
    
    printf("--- Uso Sem Typedef ---\n");
    printf("Nome: %s, Matrícula: %d, Média: %.2f\n", a1.nome, a1.matricula, a1.media);
    
    // ---------------------------------------------
    // Demonstração do uso da estrutura COM typedef
    // ---------------------------------------------
    // O uso é mais limpo, como se fosse um tipo primitivo
    Aluno a2; 
    
    // Demonstração com o typedef para tipos primitivos
    Inteiro nova_matricula = 2002;
    Nota nova_nota = 7.8;
    
    strcpy(a2.nome, "João Souza");
    a2.matricula = nova_matricula; // Usa o Inteiro (typedef para int)
    a2.media = nova_nota;          // Usa a Nota (typedef para float)
    
    printf("\n--- Uso Com Typedef ---\n");
    printf("Nome: %s, Matrícula: %d, Média: %.2f\n", a2.nome, a2.matricula, a2.media);
    
    // ---------------------------------------------
    // Demonstração do uso com ponteiros (onde typedef brilha)
    // ---------------------------------------------
    
    // Cria um ponteiro para o tipo Aluno
    Aluno *ptr_aluno = &a2;

    printf("\n--- Uso de Ponteiro com Typedef ---\n");
    printf("Nome via ponteiro: %s\n", ptr_aluno->nome);
    
    return 0;
}

#include <stdio.h>

// 1. Uso de 'typedef' para criar um apelido para um tipo básico
// Agora, em vez de 'int', podemos usar 'Inteiro' para declarar variáveis.
typedef int Inteiro;

// 2. Uso de 'typedef' para simplificar a declaração de uma 'struct'
// Definimos uma estrutura para um Ponto 2D (coordenadas x e y).
typedef struct {
    float x;
    float y;
} Ponto; // O nome 'Ponto' é o apelido (apelido para 'struct { ... }')

// Função que imprime as coordenadas de um Ponto
void imprimir_ponto(Ponto p) {
    printf("Coordenadas: (%.2f, %.2f)\n", p.x, p.y);
}

int main() {
    // Declaração de variável usando o 'typedef' Inteiro
    Inteiro numero_favorito = 42;
    printf("Meu número favorito (tipo Inteiro): %d\n", numero_favorito);

    // Declaração de variável usando o 'typedef' Ponto
    // Não precisamos escrever 'struct Ponto p1 = ...'
    Ponto p1;

    p1.x = 10.5;
    p1.y = 20.3;

    printf("\nEstrutura Ponto:\n");
    imprimir_ponto(p1);

    // Exemplo adicional: inicialização mais rápida
    Ponto p2 = { -5.0, 7.8 };
    printf("Outro ponto:\n");
    imprimir_ponto(p2);

    return 0;
}

#include <stdio.h>
#include <string.h> // Necessário para a funcao strcpy()

// 1. DEFINIÇÃO DA ESTRUTURA (STRUCT)
// Cria um novo tipo de dado chamado Aluno
struct Aluno {
    char nome[50];       // String para o nome
    int matricula;       // Numero inteiro para a matricula
    float nota_final;    // Numero decimal para a nota
};

int main() {
    // 2. DECLARAÇÃO E INICIALIZAÇÃO DA ESTRUTURA
    // Cria uma variável chamada 'estudante' do tipo struct Aluno
    struct Aluno estudante;

    // --- ENTRADA DE DADOS ---
    printf("--- Cadastro de Aluno ---\n");

    // Coletar Nome
    printf("Digite o nome do aluno: ");
    // Uso de fgets para ler a linha inteira, incluindo espacos
    fgets(estudante.nome, sizeof(estudante.nome), stdin);
    // Remove o caractere de nova linha (\n) que o fgets adiciona
    if (estudante.nome[strlen(estudante.nome) - 1] == '\n') {
        estudante.nome[strlen(estudante.nome) - 1] = '\0';
    }

    // Coletar Matricula
    printf("Digite a matricula (apenas numeros): ");
    scanf("%d", &estudante.matricula);

    // Coletar Nota Final
    printf("Digite a nota final: ");
    scanf("%f", &estudante.nota_final);

    // --- PROCESSAMENTO E SAÍDA DE DADOS ---
    printf("\n--- Dados do Aluno Cadastrado ---\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Matricula: %d\n", estudante.matricula);
    printf("Nota Final: %.2f\n", estudante.nota_final);

    // 3. ESTRUTURA CONDICIONAL (Usando o dado da struct)
    printf("Situacao: ");
    if (estudante.nota_final >= 7.0) {
        printf("APROVADO\n");
    } else if (estudante.nota_final >= 5.0) {
        printf("RECUPERACAO\n");
    } else {
        printf("REPROVADO\n");
    }

    return 0;
}

#include <stdio.h>

// 1. Definindo a estrutura (struct) para um Ponto 2D
struct Ponto2D {
    int x;
    int y;
};

// 2. Usando typedef para dar um apelido (alias) à estrutura
// 'Ponto' agora é um apelido para 'struct Ponto2D'
typedef struct Ponto2D Ponto;

// --- Função Principal ---
int main() {
    // 3. Declarando variáveis usando o apelido 'Ponto' (mais limpo)
    // Em vez de "struct Ponto2D p1;", usamos apenas "Ponto p1;"
    Ponto p1;
    Ponto p2;

    // 4. Atribuindo valores
    p1.x = 10;
    p1.y = 5;

    p2.x = -3;
    p2.y = 8;

    // 5. Imprimindo os valores
    printf("--- Exemplo de Uso de typedef ---\n");
    printf("Ponto 1 (x, y): (%d, %d)\n", p1.x, p1.y);
    printf("Ponto 2 (x, y): (%d, %d)\n", p2.x, p2.y);

    // 6. Demonstração extra: typedef para um tipo básico
    typedef int Inteiro;
    Inteiro idade = 25;
    printf("Idade (usando Inteiro, um apelido para int): %d\n", idade);

    return 0;
}

#include <stdio.h>
#include <string.h>

// 1. Definição da estrutura usando typedef
// "Aluno" passa a ser o nome do tipo de dado
typedef struct {
    char nome[50];
    int idade;
    float mediaFinal;
} Aluno;

int main() {
    // 2. Declarando variáveis diretamente com o novo nome (sem "struct")
    Aluno aluno1;
    Aluno aluno2;

    // Atribuindo dados ao aluno 1
    strcpy(aluno1.nome, "Carlos Silva");
    aluno1.idade = 20;
    aluno1.mediaFinal = 8.5;

    // Atribuindo dados ao aluno 2
    strcpy(aluno2.nome, "Ana Souza");
    aluno2.idade = 22;
    aluno2.mediaFinal = 9.2;

    // Exibindo os dados
    printf("--- Relatorio de Alunos ---\n");
    printf("Aluno: %s | Idade: %d | Media: %.2f\n", aluno1.nome, aluno1.idade, aluno1.mediaFinal);
    printf("Aluno: %s | Idade: %d | Media: %.2f\n", aluno2.nome, aluno2.idade, aluno2.mediaFinal);

    return 0;
}