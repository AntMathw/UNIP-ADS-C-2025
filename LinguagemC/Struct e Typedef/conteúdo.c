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

#include <stdio.h>
#include <stdlib.h> // Para malloc e free

// --- 1. Typedef para Tipos Primitivos ---

// Cria um apelido para 'int' para representar ID
typedef int ID_do_Registro;
// Cria um apelido para 'float' para representar uma medida
typedef float Medida_Em_Metros;
// Cria um apelido para 'unsigned char' para representar um byte de dados
typedef unsigned char Byte_De_Dados;

// --- 2. Typedef para Ponteiros ---

// Cria um apelido para um ponteiro para 'int'
typedef int* PtrInteiro;
// Cria um apelido para um ponteiro para 'char' (comumente usado para strings)
typedef char* String;

// --- 3. Typedef para Arrays ---

// Cria um novo tipo que é um array de 10 inteiros
typedef int Vetor10[10];
// Cria um novo tipo que é um array de 20 caracteres (buffer)
typedef char Buffer_20[20];

// --- 4. Typedef com Structs ---

// 4.1. Definindo a struct e o typedef ao mesmo tempo (forma mais comum e limpa)
typedef struct {
    ID_do_Registro id;          // Usando o typedef de tipo primitivo
    Buffer_20 nome;             // Usando o typedef de array
    Medida_Em_Metros altura;
} Pessoa; // 'Pessoa' é o novo nome do tipo struct

// 4.2. Usando o nome da struct (opcional, mas bom para referências recursivas)
typedef struct No_S {
    Pessoa dados;
    struct No_S *proximo; // Referência recursiva usando o nome da struct
} No_Simples; // 'No_Simples' é o novo nome do tipo struct No_S

// 4.3. Typedef para um ponteiro para a struct (comum em listas encadeadas)
typedef No_Simples* Lista; // 'Lista' é um ponteiro para 'No_Simples'

// --- 5. Typedef com Unions ---

// Cria uma union para armazenar diferentes tipos de dados na mesma localização de memória
typedef union {
    int valor_inteiro;
    float valor_flutuante;
    String valor_string;
} ValorGenerico; // 'ValorGenerico' é o novo nome do tipo union

// --- 6. Typedef para Ponteiros para Funções ---

// Define a assinatura de uma função:
// Ela recebe (int a, int b) e retorna um 'int'
typedef int (*OperacaoMatematica)(int a, int b);

// Implementação das funções que correspondem à assinatura 'OperacaoMatematica'
int somar(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

// Função que usa o typedef de ponteiro para função
int executar_operacao(OperacaoMatematica operacao, int x, int y) {
    return operacao(x, y);
}

// --- Funções de Demonstração ---

void demonstrar_tipos_primitivos() {
    printf("--- 1. Tipos Primitivos ---\n");
    ID_do_Registro meu_id = 1001;
    Medida_Em_Metros minha_altura = 1.75f;
    Byte_De_Dados flag = 0xFF;

    printf("ID: %d\n", meu_id);
    printf("Altura: %.2f metros\n", minha_altura);
    printf("Flag (byte): 0x%X\n\n", flag);
}

void demonstrar_ponteiros_e_arrays() {
    printf("--- 2. Ponteiros e Arrays ---\n");

    // Uso do typedef PtrInteiro
    int numero = 42;
    PtrInteiro ptr_num = &numero;
    printf("Valor apontado por PtrInteiro: %d\n", *ptr_num);

    // Uso do typedef String
    String saudacao = "Ola, Typedef!";
    printf("String: %s\n", saudacao);

    // Uso do typedef Vetor10
    Vetor10 meu_vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Primeiro elemento do Vetor10: %d\n", meu_vetor[0]);

    // Uso do typedef Buffer_20
    Buffer_20 nome_buffer = "C Programming";
    printf("Buffer: %s\n\n", nome_buffer);
}

void demonstrar_structs() {
    printf("--- 3. Structs ---\n");

    Pessoa p1 = {
        .id = 2002, // Usa ID_do_Registro
        .altura = 1.83f // Usa Medida_Em_Metros
    };
    // Copiar string com segurança para o Buffer_20
    snprintf(p1.nome, sizeof(p1.nome), "Carlos Silva");

    printf("Pessoa 1 - ID: %d, Nome: %s, Altura: %.2f\n",
           p1.id, p1.nome, p1.altura);

    // Demonstração da Lista/No_Simples
    Lista minha_lista = (Lista)malloc(sizeof(No_Simples));
    if (minha_lista == NULL) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        return;
    }

    minha_lista->dados = p1;
    minha_lista->proximo = NULL;

    printf("Nó da Lista - Nome da Pessoa: %s\n\n", minha_lista->dados.nome);

    free(minha_lista); // Liberar a memória
}

void demonstrar_unions() {
    printf("--- 4. Unions ---\n");

    ValorGenerico v;

    // Armazenar um inteiro
    v.valor_inteiro = 500;
    printf("Valor Inteiro: %d\n", v.valor_inteiro);

    // Armazenar um flutuante (sobrescreve o inteiro)
    v.valor_flutuante = 3.14159f;
    printf("Valor Flutuante: %.5f\n", v.valor_flutuante);

    // Armazenar uma string (sobrescreve o flutuante - cuidado com strings aqui)
    // Usando malloc para a string se fosse necessário, mas para demonstração:
    v.valor_string = "Tipo Misto";
    printf("Valor String: %s\n\n", v.valor_string);
}

void demonstrar_ponteiros_para_funcoes() {
    printf("--- 5. Ponteiros para Funções ---\n");

    // 5.1. Atribuição direta usando o typedef
    OperacaoMatematica op_soma = somar;
    int resultado_soma = op_soma(10, 5);
    printf("Resultado da Soma (10 + 5): %d\n", resultado_soma);

    // 5.2. Passando a função como argumento
    int resultado_mult = executar_operacao(multiplicar, 10, 5);
    printf("Resultado da Multiplicação (10 * 5): %d\n\n", resultado_mult);
}

int main() {
    demonstrar_tipos_primitivos();
    demonstrar_ponteiros_

#include <stdio.h>

// 1. Usando typedef em tipos primitivos
// Agora, onde eu escrever 'Reais', o C entende que é um 'float'
typedef float Reais;

// 2. Usando typedef em Structs (O uso mais comum!)
// Sem o typedef, teriamos que escrever "struct Heroi" toda vez.
typedef struct {
    char nome[30];
    int nivel;
    Reais vida;  // Usando o nosso apelido 'Reais'
    Reais ataque;
} Heroi;

int main() {
    printf("--- Criador de Personagem ---\n");

    // 3. Declarando a variável
    // Note que não preciso escrever "struct Heroi player1".
    // Apenas "Heroi" basta, pois é o apelido que criamos.
    Heroi player1;

    // Entrada de dados
    printf("Nome do heroi: ");
    // %29s limita a leitura para evitar estourar o buffer
    scanf("%29s", player1.nome); 

    printf("Nivel inicial: ");
    scanf("%d", &player1.nivel);

    printf("Vida (HP): ");
    scanf("%f", &player1.vida);

    printf("Poder de Ataque: ");
    scanf("%f", &player1.ataque);

    // Saída de dados
    printf("\n--- Status do Heroi ---\n");
    printf("Nome:   %s\n", player1.nome);
    printf("Nivel:  %d\n", player1.nivel);
    // %.1f para uma casa decimal
    printf("Vida:   %.1f HP\n", player1.vida); 
    printf("Ataque: %.1f pts\n", player1.ataque);

    return 0;
}
