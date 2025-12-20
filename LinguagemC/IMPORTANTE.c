#include <stdio.h>
#include <string.h>

int main() {

    void lerstring(char * buffer, int tamanho){
        if(fgets(buffer,tamanho,stdin) != NULL){
            buffer[strcspn(buffer,"\n") = '\0';
        }
    }
    
    

    return 0;
}

#include <stdio.h>

// Definição de Cores (Macros) para deixar o código limpo
#define VERDE "\033[1;32m"
#define VERMELHO "\033[1;31m"
#define RESET "\033[0m" // Serve para desligar a cor

int main() {
    // 1. Declaração de Variáveis
    float valor_casa, salario, prestacao, limite;
    int anos, meses;

    // Cabeçalho bonito
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("     ANALISADOR DE EMPRESTIMOS    \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    // 2. Entrada de Dados
    printf("Qual o valor da casa? R$ ");
    scanf("%f", &valor_casa);

    printf("Salario do comprador? R$ ");
    scanf("%f", &salario);

    printf("Em quantos anos vai pagar? ");
    scanf("%d", &anos);

    // 3. Validação de Segurança (Evitar divisão por zero)
    if (anos <= 0) {
        printf("\n%sERRO: O tempo de pagamento deve ser maior que zero.%s\n", VERMELHO, RESET);
        return 1; // Encerra o programa indicando erro
    }

    // 4. Processamento
    meses = anos * 12;
    prestacao = valor_casa / meses;
    limite = salario * 0.30; // 30% do salário

    // 5. Exibição dos Dados Calculados
    // %.2f limita a 2 casas decimais
    printf("\n--- Relatorio ---\n");
    printf("Valor da Casa:    R$ %.2f\n", valor_casa);
    printf("Tempo:            %d anos (%d meses)\n", anos, meses);
    printf("Prestacao Mensal: R$ %.2f\n", prestacao);
    printf("Limite Maximo:    R$ %.2f (30%% do salario)\n", limite);
    
    printf("-----------------\n");
    printf("STATUS: ");

    // 6. Lógica de Decisão
    if (prestacao <= limite) {
        // %s insere o código da cor e depois o RESET desliga
        printf("%sEMPRESTIMO CONCEDIDO!%s\n", VERDE, RESET);
        printf("Parabens! A prestacao cabe no seu bolso.\n");
    } else {
        printf("%sEMPRESTIMO NEGADO!%s\n", VERMELHO, RESET);
        printf("A parcela excede o limite de 30%% do seu salario.\n");
    }

    return 0;
}
