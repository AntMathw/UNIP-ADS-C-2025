///MATERIAL DE ESTOUDOS EM DESENVOLVIMENTO

#include <stdio.h>
#include <string.h> 
#include <ctype.h>  

// Compatibilidade para o "Sleep" funcionar em Windows e Linux
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

// Função para deixar a primeira letra maiúscula (Equivalente ao .capitalize())
void formatar_nome(char str[]) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char nome[50], sobrenome[50];

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("                                        \n");
    printf("                BEM VINDO AO SISTEMA                             \n");
    printf("                          DE                 \n");
    printf("                CADASTRO DE USUARIO          \n");
    printf("                                         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    SLEEP_MS(3000);

    printf("Ola usuario, entao vamos comecar o seu cadastro!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    SLEEP_MS(3000);

    printf("Primeiramente gostaria de saber seu nome e sobrenome!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    SLEEP_MS(3000);

    return 0;
}
