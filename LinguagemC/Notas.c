#include <stdio.h>

int main() {
    int nota;

    // Solicita a nota ao usuário
    printf("Digite a nota (0-100): ");
    scanf("%d", &nota);

    // Usa if, else if e else para avaliar a nota
    if (nota >= 90) {
        printf("Excelente! Voce esta de parabens.\n");
    } else if (nota >= 70) {
        printf("Muito bom! Voce foi aprovado.\n");
    } else if (nota >= 50) {
        printf("Aprovado, mas com ressalvas. Voce precisa estudar mais.\n");
    } else {
        printf("Infelizmente, voce foi reprovado. Estude para a proxima vez.\n");
    }

    return 0;
}