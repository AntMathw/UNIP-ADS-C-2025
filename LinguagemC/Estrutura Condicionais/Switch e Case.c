#include <stdio.h>

int main() {
    int opcao;

    // Pede ao usuário para digitar um número
    printf("Digite um numero de 1 a 3: ");
    scanf("%d", &opcao);

    // O 'switch' verifica o valor da variável 'opcao'
    switch (opcao) {
        // Se a opcao for 1, executa este bloco
        case 1:
            printf("Voce escolheu a opcao 1.\n");
            break; // O 'break' e essencial para sair do 'switch' apos a execucao deste case
        
        // Se a opcao for 2, executa este bloco
        case 2:
            printf("Voce escolheu a opcao 2.\n");
            break;
            
        // Se a opcao for 3, executa este bloco
        case 3:
            printf("Voce escolheu a opcao 3.\n");
            break;
            
        // Se a opcao nao for 1, 2 ou 3, executa este bloco
        default:
            printf("Opcao invalida. Por favor, digite um numero entre 1 e 3.\n");
            break;
    }

    return 0;
}
