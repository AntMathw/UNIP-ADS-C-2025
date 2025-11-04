#include <stdio.h>
#include <stdlib.h> // Para a função rand() e srand()
#include <time.h>   // Para a função time()

// Funcao para lancar um dado e retornar um valor entre 1 e 6
int lancar_dado() {
    // rand() % 6 gera um numero entre 0 e 5.
    // Adicionando 1, obtemos um numero entre 1 e 6.
    return (rand() % 6) + 1;
}

int main() {
    int dado1, dado2, soma, aposta;

    // Inicializa o gerador de numeros aleatorios.
    // A funcao time(0) garante que a semente (seed) seja diferente a cada execucao,
    // tornando os resultados mais 'aleatorios'.
    srand(time(0));

    printf("======================================\n");
    printf("        JOGO DE DADOS EM C\n");
    printf("======================================\n");
    printf("Regras: Adivinhe a soma dos dois dados.\n");

    // --- ENTRADA DA APOSTA ---
    printf("\nFaca sua aposta:\n");
    printf("1 - Soma sera MENOR que 7\n");
    printf("2 - Soma sera IGUAL a 7\n");
    printf("3 - Soma sera MAIOR que 7\n");
    printf("Digite sua escolha (1, 2 ou 3): ");
    scanf("%d", &aposta);

    // Valida a aposta do usuario
    if (aposta < 1 || aposta > 3) {
        printf("\nOpcao invalida. O jogo foi encerrado.\n");
        return 1; // Retorna com erro
    }

    // --- LANÇAMENTO DOS DADOS ---
    printf("\n--- LANCANDO OS DADOS ---\n");
    
    // Chama a funcao para lancar os dois dados
    dado1 = lancar_dado();
    dado2 = lancar_dado();
    soma = dado1 + dado2;

    printf("Dado 1 caiu em: %d\n", dado1);
    printf("Dado 2 caiu em: %d\n", dado2);
    printf("A soma total e: %d\n", soma);

    // --- AVALIACAO DO RESULTADO ---
    printf("\n--- RESULTADO DA APOSTA ---\n");

    // Determina o resultado real do lancamento
    int resultado_real;
    if (soma < 7) {
        resultado_real = 1; // Menor que 7
    } else if (soma == 7) {
        resultado_real = 2; // Igual a 7
    } else { // soma > 7
        resultado_real = 3; // Maior que 7
    }

    // Compara a aposta do jogador com o resultado real
    if (aposta == resultado_real) {
        printf("PARABENS! Voce acertou a aposta!\n");
    } else {
        printf("Que pena! Voce errou a aposta.\n");
    }

    printf("======================================\n");
    return 0;
}
