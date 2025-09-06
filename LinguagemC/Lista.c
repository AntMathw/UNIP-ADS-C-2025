#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100

// Estrutura que guarda os dados de cada pessoa
struct Pessoa {
    char nome[50];
    int idade;
    char cpf[15];
};

int main() {
    struct Pessoa lista[MAX_PESSOAS];
    int qtd, i;

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &qtd);
    getchar(); // limpar buffer do Enter

    if (qtd > MAX_PESSOAS) {
        printf("Número máximo permitido é %d.\n", MAX_PESSOAS);
        return 1;
    }

    for (i = 0; i < qtd; i++) {
        printf("\nPessoa %d:\n", i + 1);

        printf("Nome: ");
        fgets(lista[i].nome, sizeof(lista[i].nome), stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0'; // remove '\n'

        printf("Idade: ");
        scanf("%d", &lista[i].idade);
        getchar(); // limpar buffer

        printf("CPF: ");
        fgets(lista[i].cpf, sizeof(lista[i].cpf), stdin);
        lista[i].cpf[strcspn(lista[i].cpf, "\n")] = '\0';
    }

    // Mostrando lista
    printf("\n--- Lista de Pessoas Cadastradas ---\n");
    for (i = 0; i < qtd; i++) {
        printf("Nome: %s | Idade: %d | CPF: %s\n", lista[i].nome, lista[i].idade, lista[i].cpf);
    }

    return 0;
}
