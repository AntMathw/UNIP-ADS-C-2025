///MATERIAL DE ESTOUDOS EM DESENVOLVIMENTO

#include <stdio.h>
#include <string.h> 
#include <ctype.h>  

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

void formatar_nome(char str[]) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    // Inicializando com "" para garantir que a memória esteja limpa
    char nome[50] = "";
    char sobrenome[50] = "";

    // Ajustei o cabeçalho para ficar simétrico
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("|                                         |\n");
    printf("|          BEM VINDO AO SISTEMA           |\n");
    printf("|                   DE                    |\n");
    printf("|           CADASTRO DE USUARIO           |\n");
    printf("|                                         |\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    SLEEP_MS(2000);

    printf("\nOla usuario, entao vamos comecar o seu cadastro!\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(2000);

    printf("Primeiramente gostaria de saber seu nome e sobrenome!\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(2000);

    // Exemplo de como ler com segurança:
    printf("Digite seu nome: ");
    scanf("%s", nome); 
    formatar_nome(nome);

    printf("Nome registrado: %s\n", nome);

    return 0;
}
