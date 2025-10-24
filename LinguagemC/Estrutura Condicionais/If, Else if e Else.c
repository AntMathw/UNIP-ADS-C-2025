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
