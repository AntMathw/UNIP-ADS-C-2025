#include <stdio.h>
#include <string.h> 
#include <ctype.h>

// Configuração para exportar funções para o Python sem quebrar o código original
#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #define EXPORT
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

// --- FUNÇÕES QUE O PYTHON VAI CHAMAR (DENTRO DA ESTRUTURA ORIGINAL) ---

EXPORT int validar_cadastro(const char* cpf, const char* email) {
    // Mantendo sua lógica de retorno: 1 para CPF, 2 para Email
    if (strlen(cpf) != 11) return 1;
    if (strchr(email, '@') == NULL) return 2;
    return 0; 
}

EXPORT int avaliar_senha(const char* senha) {
    int tamanho = strlen(senha);
    int tem_numero = 0;
    int tem_letra = 0;

    if (tamanho < 6 ) return 1; 

    for (int i = 0; i < tamanho; i ++) {
        if (isdigit(senha[i])) tem_numero = 1;
        if (isalpha(senha[i])) tem_letra = 1;
    }

    if (tamanho >= 8 && tem_numero && tem_letra) return 3; 
    if (tamanho >= 6 && tem_numero && tem_letra) return 2; 

    return 1;
}

// --- SUA ESTRUTURA ORIGINAL DE FORMATAÇÃO ---

void formatar_nome(char str[]) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]); 
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]); 
        }
    }
}

// --- SEU MÉTODO MAIN ORIGINAL (PARA EXECUTAR O C PRIMEIRO) ---

int main() {
    char nome[50] = "";
    char sobrenome[50] = "";
    int idade;
    char cpf[15] = ""; 
    char email[100] = "";
    int arroba_encontrado = 0;

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("|          BEM VINDO AO SISTEMA           |\n");
    printf("|           CADASTRO DE USUARIO           |\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    SLEEP_MS(2000);

    printf("\nOla usuario, entao vamos comecar o seu cadastro!\n");
    printf("-------------------------------------------\n");
    SLEEP_MS(1000);

    // --- LOOP NOME ---
    while (1) {
        printf("Digite seu nome: ");
        if (fgets(nome, sizeof(nome), stdin) != NULL) {
            nome[strcspn(nome, "\n")] = '\0'; 
            if (strlen(nome) == 0) {
                printf("Erro: Preencha o campo corretamente!\n");
            } else if (strlen(nome) <= 2) {
                printf("Erro: Nome muito curto! Tente novamente.\n");
            } else {
                formatar_nome(nome);
                break; 
            }
        }
    }

    // --- LOOP SOBRENOME ---
    while (1) {
        printf("Certo, agora digite seu sobrenome: ");
        if (fgets(sobrenome, sizeof(sobrenome), stdin) != NULL) {
            sobrenome[strcspn(sobrenome, "\n")] = '\0';
            if (strlen(sobrenome) <= 2) {
                printf("Erro: Sobrenome muito curto!\n");
            } else {
                formatar_nome(sobrenome);
                break;
            }
        }
    }

    // --- LOOP IDADE ---
    while (1) {
        printf("Digite sua idade: ");
        if (scanf("%d", &idade) != 1) { 
            printf("Erro: Digite apenas numeros.\n");
            while (getchar() != '\n'); 
            continue; 
        }
        if (idade <= 0 || idade > 120) {
            printf("Idade invalida!\n");
        } else {
            break; 
        }
    }

    // --- LOOP CPF ---
    while (1) {
        printf("Digite seu CPF (11 numeros): ");
        scanf("%s", cpf);
        if(strlen(cpf) == 11) break;
        printf("CPF invalido!\n");
    }

    // --- LOOP EMAIL ---
    while (1) {
        printf("Digite seu email: ");
        scanf("%s", email);
        if (strchr(email, '@') != NULL) break;
        printf("Email invalido!\n");
    }

    // --- RESUMO FINAL ---
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("| Nome: %s %s\n", nome, sobrenome);
    printf("| Idade: %d | CPF: %s\n", idade, cpf);
    printf("| Email: %s\n", email);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    return 0;
}
