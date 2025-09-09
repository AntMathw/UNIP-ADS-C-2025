#include <stdio.h>

int main() {
    float nota, soma_notas = 0.0;
    int contador_notas = 0;
    char continuar;

    printf("--- Calculadora de Media de Notas ---\n");

    do {
        printf("Digite uma nota: ");
        scanf("%f", &nota);

        soma_notas += nota; // Adiciona a nota atual a soma_notas
        contador_notas++; // Incrementa o contador de notas

        // Limpa o buffer do teclado para evitar problemas com o scanf
        while (getchar() != '\n');

        printf("Deseja adicionar mais uma nota? (s/n): ");
        scanf("%c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Verifica se alguma nota foi inserida para evitar divisao por zero
    if (contador_notas > 0) {
        float media = soma_notas / contador_notas;
        printf("\nMedia final: %.2f\n", media);
    } else {
        printf("\nNenhuma nota foi inserida.\n");
    }

    return 0;
}