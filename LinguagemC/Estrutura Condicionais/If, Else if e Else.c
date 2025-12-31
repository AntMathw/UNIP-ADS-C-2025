 #include <stdio.h>
 int main() {
    int a = 3;
    if (a > 5) {
        printf("a é maior que 5\n");
    } else {
        printf("a não é maior que 5\n");
    }
    return 0;
 

#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O numero e positivo.\n");
    } else if (numero < 0) {
        printf("O numero e negativo.\n");
    } else {
        printf("O numero e zero.\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    // Variáveis para armazenar o saldo e o valor da compra
    float saldo_disponivel = 550.00;
    float valor_da_compra = 499.99;

    printf("--- Simulador de Compra ---\n");
    printf("Saldo disponível: R$ %.2f\n", saldo_disponivel);
    printf("Valor da compra:  R$ %.2f\n", valor_da_compra);
    printf("---------------------------\n");

    // A estrutura if/else verifica se o saldo é suficiente para a compra
    if (saldo_disponivel >= valor_da_compra) {
        // Bloco 'if': Executado se a condição for VERDADEIRA (saldo >= valor da compra)
        printf("\nCOMPRA APROVADA!\n");
        printf("Seu novo saldo será: R$ %.2f\n", saldo_disponivel - valor_da_compra);
    } else {
        // Bloco 'else': Executado se a condição for FALSA (saldo < valor da compra)
        printf("\nCOMPRA RECUSADA!\n");
        printf("Motivo: Saldo insuficiente. Faltam R$ %.2f para a compra.\n", valor_da_compra - saldo_disponivel);
    }

    return 0;
}

#IDADE de um adolescente

#include <stdio.h>

int main() {
    int idade;

    // Solicita a idade ao usuário
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // Estrutura condicional
    if (idade < 0) {
        printf("Idade inválida. A idade não pode ser negativa.\n");
    } else if (idade < 13) {
        printf("Você é uma criança.\n");
    } else if (idade < 18) {
        printf("Você é um adolescente.\n");
    } else if (idade < 60) {
        printf("Você é um adulto.\n");
    } else { // idade >= 60
        printf("Você é um idoso.\n");
    }

    return 0;
}

#include <stdio.h>

// Definição dos critérios de aprovação
#define NOTA_MINIMA_APROVACAO 7.0
#define NOTA_MINIMA_RECUPERACAO 5.0

int main() {
    // Declaração da variável para armazenar a nota do aluno
    float nota;

    // --- ENTRADA DE DADOS ---
    printf("Sistema de Avaliacao de Aluno\n");
    printf("-------------------------------\n");
    printf("Digite a nota final do aluno (Ex: 8.5): ");
    // Lê o valor digitado pelo usuário e armazena na variável 'nota'
    scanf("%f", &nota);

    // --- ESTRUTURA CONDICIONAL (IF-ELSE IF-ELSE) ---
    printf("\nResultado da Avaliacao:\n");

    // Verifica a primeira condicao: Aprovado
    if (nota >= NOTA_MINIMA_APROVACAO) {
        printf("Parabens! O aluno esta APROVADO.\n");
    }
    // Se a primeira condicao for falsa, verifica a segunda: Recuperacao
    else if (nota >= NOTA_MINIMA_RECUPERACAO) {
        printf("Atencao! O aluno esta em RECUPERACAO.\n");
    }
    // Se nenhuma das condicoes anteriores for verdadeira: Reprovado
    else {
        printf("Infelizmente, o aluno esta REPROVADO.\n");
    }

    printf("\nPrograma finalizado.\n");

    return 0;
}

#include <stdio.h>

// Cores para deixar o terminal bonito
#define QUENTE "\033[1;31m"  // Vermelho
#define MORNO  "\033[1;33m"  // Amarelo
#define BOM    "\033[1;32m"  // Verde
#define FRIO   "\033[1;34m"  // Azul
#define RESET  "\033[0m"

int main() {
    float temperatura;

    printf("=== ASSISTENTE DE CLIMA ===\n");
    printf("Quantos graus esta fazendo agora? ");
    scanf("%f", &temperatura);

    printf("\n>>> Analise: ");

    // 1. Estrutura Condicional
    // O programa testa as condições de cima para baixo.
    
    if (temperatura > 32) {
        // Se for maior que 32, entra aqui e PULA todo o resto.
        printf("%sCALOR EXTREMO!%s\n", QUENTE, RESET);
        printf("Dica: Beba muita agua e fique na sombra.\n");
    
    } else if (temperatura >= 25) {
        // Só chega aqui se for menor ou igual a 32.
        printf("%sDia de Verao.%s\n", MORNO, RESET);
        printf("Dica: Otimo para praia ou piscina.\n");
    
    } else if (temperatura >= 15) {
        // Só chega aqui se for menor que 25.
        printf("%sClima Agradavel.%s\n", BOM, RESET);
        printf("Dica: Bom para caminhar no parque.\n");
    
    } else if (temperatura >= 5) {
        // Só chega aqui se for menor que 15.
        printf("%sEsta Frio.%s\n", FRIO, RESET);
        printf("Dica: Use casaco e tome cafe quente.\n");
    
    } else {
        // Se nenhuma das anteriores for verdade (menor que 5).
        printf("%sCONGELANTE!%s\n", FRIO, RESET);
        printf("Dica: Fique em casa debaixo das cobertas!\n");
    }

    return 0;
}

#include <stdio.h>

#define VERDE "\033[1;32m"
#define AMARELO "\033[1;33m"
#define VERMELHO "\033[1;31m"
#define RESET "\033[0m"

int main() {
    float velocidade, excesso, valor_multa;
    const float LIMITE = 80.0; // Usar const é boa prática para valores fixos

    printf("=== RADAR ELETRONICO 2.0 ===\n");
    printf("Velocidade da via: %.0f km/h\n", LIMITE);
    printf("----------------------------\n");
    
    printf("Digite a velocidade capturada (km/h): ");
    scanf("%f", &velocidade);

    printf("\n>>> RESULTADO: ");

    // 1. Primeira verificação: Está dentro do limite?
    if (velocidade <= LIMITE) {
        printf("%sDENTRO DO LIMITE%s\n", VERDE, RESET);
        printf("Boa viagem! Dirija com seguranca.\n");

    } 
    // 2. Segunda verificação: Está na margem de tolerância? (Até +10km/h)
    // Note o uso do && (E) para garantir o intervalo exato
    else if (velocidade > LIMITE && velocidade <= (LIMITE + 10)) {
        printf("%sADVERTENCIA (Tolerancia)%s\n", AMARELO, RESET);
        printf("Cuidado, voce esta acima do limite, mas dentro da tolerancia.\n");
        printf("Reduza a velocidade!\n");

    } 
    // 3. Caso contrário: Multa!
    else {
        printf("%sMULTADO!%s\n", VERMELHO, RESET);
        
        // Calcular o prejuízo
        excesso = velocidade - LIMITE;
        valor_multa = excesso * 10.00; // 10 reais por km excedido

        printf("Voce passou a %.1f km/h (%.1f km/h acima).\n", velocidade, excesso);
        printf("Valor da Multa: R$ %.2f\n", valor_multa);
    }

    return 0;
}
