#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mostrar a escolha como texto
const char* escolhaTexto(int escolha) {
    switch (escolha) {
        case 1: return "Pedra";
        case 2: return "Papel";
        case 3: return "Tesoura";
        default: return "Desconhecido";
    }
}

int main() {
    int jogador, computador;
    char jogarNovamente;

    // Inicializa gerador de números aleatórios
    srand(time(NULL));

    do {
        // Menu
        printf("\n=== JOKENPÔ ===\n");
        printf("Escolha uma opção:\n");
        printf("1 - Pedra\n");
        printf("2 - Papel\n");
        printf("3 - Tesoura\n");
        printf("Sua escolha: ");
        scanf("%d", &jogador);

        // Verifica se a escolha é válida
        if (jogador < 1 || jogador > 3) {
            printf("Escolha inválida. Tente novamente.\n");
            continue;
        }

        // Computador faz a escolha
        computador = rand() % 3 + 1;

        printf("Você escolheu: %s\n", escolhaTexto(jogador));
        printf("Computador escolheu: %s\n", escolhaTexto(computador));

        // Determina o vencedor
        if (jogador == computador) {
            printf("Empate!\n");
        } else if (
            (jogador == 1 && computador == 3) ||
            (jogador == 2 && computador == 1) ||
            (jogador == 3 && computador == 2)
        ) {
            printf("Você venceu!\n");
        } else {
            printf("Você perdeu!\n");
        }

        // Pergunta se o usuário quer jogar novamente
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n");
    return 0;
}
