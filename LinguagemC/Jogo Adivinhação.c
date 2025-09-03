#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSecreto, palpite, tentativas = 0;
    srand(time(0));
    numeroSecreto = rand() % 100 + 1; // Gera um número entre 1 e 100

    printf("Bem-vindo ao jogo de adivinhação!\n");
    printf("Estou pensando em um número entre 1 e 100. Tente adivinhar!\n");

    do {
        printf("Digite seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite > numeroSecreto) {
            printf("Muito alto! Tente um número menor.\n");
        } else if (palpite < numeroSecreto) {
            printf("Muito baixo! Tente um número maior.\n");
        } else {
            printf("Parabéns! Você acertou em %d tentativas!\n", tentativas);
        }
    } while (palpite != numeroSecreto);

    return 0;
}