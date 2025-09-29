#include <stdio.h>

int main() {
    int opcao;

    // Pede ao usuário para digitar um número
    printf("Digite um numero de 1 a 3: ");
    scanf("%d", &opcao);

    // O 'switch' verifica o valor da variável 'opcao'
    switch (opcao) {
        // Se a opcao for 1, executa este bloco
        case 1:
            printf("Voce escolheu a opcao 1.\n");
            break; // O 'break' e essencial para sair do 'switch' apos a execucao deste case
        
        // Se a opcao for 2, executa este bloco
        case 2:
            printf("Voce escolheu a opcao 2.\n");
            break;
            
        // Se a opcao for 3, executa este bloco
        case 3:
            printf("Voce escolheu a opcao 3.\n");
            break;
            
        // Se a opcao nao for 1, 2 ou 3, executa este bloco
        default:
            printf("Opcao invalida. Por favor, digite um numero entre 1 e 3.\n");
            break;
    }

    return 0;
}



#include <stdio.h>

int main() {
    char operador;
    double num1, num2, resultado;

    // Solicita a entrada da operação e dos números
    printf("Digite um operador (+, -, *, /): ");
    scanf(" %c", &operador); // O espaço antes de %c ajuda a consumir qualquer caractere de nova linha pendente
    
    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%lf", &num2);

    // Estrutura switch para escolher a operação
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
            break; // Sai do switch após a execução
            
        case '-':
            resultado = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
            break;
            
        case '*':
            resultado = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
            break;
            
        case '/':
            // Verifica se o segundo número é zero antes de dividir
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
            } else {
                printf("Erro! Divisão por zero não é permitida.\n");
            }
            break;
            
        // O 'default' é executado se nenhum dos 'case' corresponder
        default:
            printf("Erro! Operador inválido.\n");
    }

    return 0;
}