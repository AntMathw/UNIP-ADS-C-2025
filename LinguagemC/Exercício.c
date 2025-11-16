#include <stdio.h>

int main() {
    float nota, soma_notas = 0.0;
    int contador_notas = 0;
    char continuar;

    printf("--- Calculadora de Media de Notas ---\n");

    do {
        printf("Digite uma nota: ");
        scanf("%f", &nota);

        soma_notas += nota; 
        contador_notas++; 

        
        while (getchar() != '\n');

        printf("Deseja adicionar mais uma nota? (s/n): ");
        scanf("%c", &continuar);

    } while (continuar == 's' || continuar == 'S');

   
    if (contador_notas > 0) {
        float media = soma_notas / contador_notas;
        printf("\nMedia final: %.2f\n", media);
    } else {
        printf("\nNenhuma nota foi inserida.\n");
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    // Declaração de variáveis para o número de entrada e o resultado.
    double numero;
    double resultado_raiz;

    // Pede ao usuário para inserir um número.
    printf("Digite um número positivo para calcular sua raiz quadrada: ");

    // Lê o número inserido pelo usuário.
    // O especificador %lf é usado para ler um 'double'.
    if (scanf("%lf", &numero) != 1) {
        printf("Entrada inválida.\n");
        return 1; // Retorna um código de erro.
    }

    // Verifica se o número é positivo, pois a raiz quadrada de números negativos 
    // geralmente resulta em números complexos (a função sqrt() padrão retorna NaN).
    if (numero >= 0) {
        // A função 'sqrt()' calcula a raiz quadrada.
        resultado_raiz = sqrt(numero);

        // Imprime o resultado. O especificador %.4f formata a saída para 4 casas decimais.
        printf("A raiz quadrada de %.2f é: %.4f\n", numero, resultado_raiz);
    } else {
        // Mensagem de erro para números negativos.
        printf("Não é possível calcular a raiz quadrada real de um número negativo.\n");
    }

    return 0; // Retorna 0 para indicar que o programa rodou com sucesso.
}