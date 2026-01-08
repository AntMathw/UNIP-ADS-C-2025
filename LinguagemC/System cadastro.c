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
    char nome[50] = "";
    char sobrenome[50] = "";
    int idade;
    char cpf[12] = "";

    // --- CABEÇALHO ---
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
    printf("Primeiro, preciso saber o seu nome e sobrenome.\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(2000);

    // --- LOOP NOME ---
    while (1) {
        printf("Digite seu nome: ");
        if (fgets(nome, sizeof(nome), stdin) != NULL) {
            SLEEP_MS(2000);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o Enter

            if (strlen(nome) == 0) {
                printf("Erro: Preencha o campo corretamente!\n");
            } else if (strlen(nome) <= 2) {
                printf("Erro: Nome muito curto! Tente novamente.\n");
            } else if (strlen(nome) >= 30) {
                printf("Erro: Nome muito longo! Tente novamente.\n");
            } else {
                formatar_nome(nome);
                break;
            }
        }
    }

   
    while (1) {
        printf("Certo, agora digite seu sobrenome: ");
        if (fgets(sobrenome, sizeof(sobrenome), stdin) != NULL) {
            SLEEP_MS(2000);
            sobrenome[strcspn(sobrenome, "\n")] = '\0';

            if (strlen(sobrenome) == 0) {
                printf("Erro: Preencha o campo corretamente!\n");
            } else if (strlen(sobrenome) <= 2) {
                printf("Erro: Sobrenome muito curto! Tente novamente.\n");
            } else if (strlen(sobrenome) >= 30) {
                printf("Erro: Sobrenome muito longo! Tente novamente.\n");
            } else {
                formatar_nome(sobrenome);
                break;
            }
        }
    }

    printf("\nSeu nome completo e: %s %s\n", nome, sobrenome);
    printf("--------------------------------------------\n");
    SLEEP_MS(2000);

    printf("Certo! Agora gostaria de saber a sua idade e seu CPF!\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(2000);

    
    while (1) {
        printf("Digite sua idade: ");
        if (scanf("%d", &idade) != 1) { 
            printf("Erro: Por favor, digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa o lixo do teclado
            continue; 
        }

        if (idade <= 0 || idade > 120) {
            printf("Idade invalida! Tente novamente (0-120).\n");
        } else {
            printf("Voce possui %d anos. Registrado com sucesso!\n", idade);
            printf("--------------------------------------------\n");
            break; 
        }
    }

    printf("\nProsseguindo para o proximo passo...\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(2000);

    while (1) {
        printf("Digite seu CPF (somente 11 numeros): ");
        if (scanf("%s", cpf) == 1){
        while (getchar() != '\n');

            if(strlen(cpf) < 11){
                printf("CPF inválido! Tente novamente.\n");
            
            } 
            else if(strlen(cpf) > 11){
                printf("CPF muito longo! Tente novamente. \n");

            } 
            else if(strlen(cpf) == 0){
                printf("Erro: Preencha o campo corretamente.\n");
            } 
            else {
                printf("Seu CPF e %s. Registrado com sucesso!\n", cpf);
                break;
        }
    }
 }
        
        printf("\nEntao usuario seu cadastro ficou assim: \n");
    printf("-------------------------------------------\n");
    printf("E importante verificar se os dados estao corretos! \n");
    SLEEP_MS(2000);
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("|                                           |\n");
    printf("|      Nome Completo: \"%s\" \"%s\"         |\n", nome, sobrenome);
    printf("|      Idade: %d anos                       |\n", idade);
    printf("|      CPF: %s                              |\n", cpf);
    printf("|                                           |\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    return 0;
}
