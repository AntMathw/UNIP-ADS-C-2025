///CÓDIGO PARA ESTUDOS DA LINGUAGEM

#include <stdio.h>
#include <ctype.h>
#include <string.h> // Necessário para strlen e strcspn

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

// Função para formatar o nome (Primeira letra maiúscula, restante minúscula)
void format_nome(char str[]) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char nome[150] = "";
    // Variáveis menu, tempo e pedido declaradas para uso futuro
    char menu[200] = "";
    int tempo;
    int pedido[10];

    // CABEÇALHO VISUAL
    printf("=================================\n");
    printf("|          COFFEE SHOP          |\n");
    printf("=================================\n");
    SLEEP_MS(1000);
    
    printf("Bem-vindo ao aplicativo do nosso Coffee Shop!\n");
    SLEEP_MS(1000);

    printf("Primeiro, gostariamos de saber o seu nome completo para iniciar seu pedido.\n");
    SLEEP_MS(1000);

    // Estrutura de repetição para validação do nome
    while (1) {
        printf("\nDigite o seu nome completo: ");
        if (fgets(nome, sizeof(nome), stdin) != NULL) {
            // Remove a quebra de linha (\n) do final da string
            nome[strcspn(nome, "\n")] = '\0';

            size_t tam = strlen(nome);

            if (tam == 0) {
                printf("Erro: O campo não pode estar vazio!\n");
            } else if (tam > 149) {
                printf("Erro: Nome acima do limite do cadastro!\n");
            } else if (tam < 2) {
                printf("Erro: Nome muito curto!\n");
            } else {
                format_nome(nome);
                break; // Sai do loop se o nome for válido
            }
        }   
    }

    printf("\nOla, %s! Vamos continuar com o seu pedido...\n", nome);

    return 0;
}
