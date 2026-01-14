#include <stdio.h>
#include <string.h> 
#include <ctype.h>  // Necessária para as funções toupper e tolower

/* CONFIGURAÇÃO MULTIPLATAFORMA PARA O SLEEP
   Detecta se o sistema é Windows ou Unix (Linux/Mac) para usar a função de pausa correta.
*/
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

/* FUNÇÃO: formatar_nome
   Objetivo: Deixar a primeira letra maiúscula e o restante minúscula (Ex: fELIPE -> Felipe).
*/
void formatar_nome(char str[]) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]); // Primeira letra para Maiúsculo
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]); // Restante para Minúsculo
        }
    }
}

int main() {
    // Declaração de variáveis com inicialização (boa prática para evitar lixo de memória)
    char nome[50] = "";
    char sobrenome[50] = "";
    int idade;
    char cpf[15] = ""; // Tamanho 15 para segurança contra estouro de buffer
    char email[100] = "";
    int arroba_encontrado = 0;

    // --- CABEÇALHO VISUAL ---
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("|          BEM VINDO AO SISTEMA           |\n");
    printf("|           CADASTRO DE USUARIO           |\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    SLEEP_MS(2000);

    printf("\nOla usuario, entao vamos comecar o seu cadastro!\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(1000);

    // --- LOOP DE VALIDAÇÃO: NOME ---
    while (1) {
        printf("Digite seu nome: ");
        if (fgets(nome, sizeof(nome), stdin) != NULL) {
            // strcspn substitui o caractere de 'nova linha' (\n) gerado pelo Enter por um fim de string (\0)
            nome[strcspn(nome, "\n")] = '\0'; 

            if (strlen(nome) == 0) {
                printf("Erro: Preencha o campo corretamente!\n");
            } else if (strlen(nome) <= 2) {
                printf("Erro: Nome muito curto! Tente novamente.\n");
            } else if (strlen(nome) >= 30) {
                printf("Erro: Nome muito longo! Tente novamente.\n");
            } else {
                formatar_nome(nome); // Aplica a formatação estética
                break; // Sai do loop se estiver tudo correto
            }
        }
    }

    // --- LOOP DE VALIDAÇÃO: SOBRENOME ---
    while (1) {
        printf("Certo, agora digite seu sobrenome: ");
        if (fgets(sobrenome, sizeof(sobrenome), stdin) != NULL) {
            sobrenome[strcspn(sobrenome, "\n")] = '\0';

            if (strlen(sobrenome) == 0) {
                printf("Erro: Preencha o campo corretamente!\n");
            } else if (strlen(sobrenome) <= 2) {
                printf("Erro: Sobrenome muito curto! Tente novamente.\n");
            } else {
                formatar_nome(sobrenome);
                break;
            }
        }
    }

    printf("\nSeu nome completo e: %s %s\n", nome, sobrenome);
    printf("--------------------------------------------\n");
    SLEEP_MS(1000);

    // --- LOOP DE VALIDAÇÃO: IDADE ---
    while (1) {
        printf("Digite sua idade: ");
        // scanf retorna o número de itens lidos com sucesso. Se for 0, o usuário digitou letras.
        if (scanf("%d", &idade) != 1) { 
            printf("Erro: Por favor, digite apenas numeros.\n");
            while (getchar() != '\n'); // LIMPEZA DE BUFFER: Remove o lixo do teclado (letras) para não travar o loop
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

    // --- LOOP DE VALIDAÇÃO: CPF ---
    while (1) {
        printf("Digite seu CPF (somente 11 numeros): ");
        if (scanf("%s", cpf) == 1){
            while (getchar() != '\n'); // Limpa o buffer para o próximo fgets não ler o "Enter"

            if(strlen(cpf) < 11){
                printf("CPF inválido! Tente novamente.\n");
            } else if(strlen(cpf) > 11){
                printf("CPF muito longo! Tente novamente. \n");
            } else {
                printf("Seu CPF e %s. Registrado com sucesso!\n", cpf);
                printf("-------------------------------------------\n");
                break;
            }
        }
    }

    // --- LOOP DE VALIDAÇÃO: EMAIL ---
    while (1) {
        printf("Digite seu email pessoal: ");
        if (fgets(email, sizeof(email), stdin) != NULL) {
            email[strcspn(email, "\n")] = '\0';

            if (strlen(email) <= 5) {
                printf("Erro: Email muito curto! Tente novamente.\n");
            } else {
                // Algoritmo simples de busca de caractere
                arroba_encontrado = 0;
                for (int i = 0; email[i] != '\0'; i++) {
                    if (email[i] == '@'){
                        arroba_encontrado = 1;
                        break;
                    }
                }
                
                if (!arroba_encontrado) {
                    printf("Erro: Email invalido! Deve conter '@'. Tente novamente.\n");
                } else {
                    printf("Email %s registrado com sucesso!\n", email);
                    printf("-------------------------------------------\n");
                    break;
                }
            }
        }
    }

    // --- RESUMO FINAL DOS DADOS ---
    SLEEP_MS(1000);
    printf("\nEntao usuario seu cadastro ficou assim: \n");
    printf("-------------------------------------------\n");
    printf("E importante verificar se os dados estao corretos! \n");
    SLEEP_MS(2000);

    // Quadro formatado para exibição profissional
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("|                                           |\n");
    printf("|      Nome Completo: \"%s\" \"%s\"             \n", nome, sobrenome);
    printf("|      Idade: %d anos                       \n", idade);
    printf("|      CPF: %s                              \n", cpf);
    printf("|      Email: %s                            \n", email); 
    printf("|                                           |\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    return 0; // Indica que o programa terminou sem erros
}
