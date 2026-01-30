#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char curso[50];
    char email[50];
} Aluno;

// Função auxiliar para limpar o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n, i;
    Aluno *alunos;

    printf("Digite o numero de alunos: ");
    if (scanf("%d", &n) != 1) return 1;
    limpar_buffer(); // Remove o '\n' que sobraria para o fgets

    // Alocação Dinâmica com verificação de erro
    alunos = (Aluno *)malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

    for(i = 0; i < n; i++) {
        printf("\n--- Cadastro do Aluno %d ---\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // Remove o \n do final

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        limpar_buffer(); // Limpa para o próximo fgets ou scanf funcionar

        printf("Curso: ");
        fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);
        alunos[i].curso[strcspn(alunos[i].curso, "\n")] = '\0';

        printf("Email: ");
        scanf("%s", alunos[i].email);
        limpar_buffer();
    }

    

    printf("\n======= LISTAGEM FINAL =======\n");
    for(i = 0; i < n; i++) {
        printf("[%d] %-20s | %d anos | Curso: %-15s | Email: %s\n", 
                i + 1, alunos[i].nome, alunos[i].idade, alunos[i].curso, alunos[i].email);
    }

    free(alunos); // Boa prática: Liberar a heap
    printf("\nMemoria liberada com sucesso.\n");

    return 0;
}
