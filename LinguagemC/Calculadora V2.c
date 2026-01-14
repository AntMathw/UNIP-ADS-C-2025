#include <stdio.h>
#include <math.h>   // Biblioteca para funções matemáticas (sqrt, pow)
#include <stdlib.h> // Necessária para comandos do sistema como limpar tela

/* MACROS DE COMPILAÇÃO:
   Garante que o código funcione tanto em Windows quanto em Linux/Unix.
*/
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
    #define CLEAR "clear"
#endif

int main() {
    // Inicialização de variáveis: evita que o programa use "lixo" da memória
    int opcao = 0;
    double num1 = 0, num2 = 0, resultado = 0;
    
    // ESTRUTURA DE REPETIÇÃO: O menu rodará pelo menos uma vez
    do {
        system(CLEAR); // Mantém o terminal limpo para uma melhor experiência do usuário (UX)
        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("|          SISTEMA DE CALCULADORA          |\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        
        // Exibição do menu (organizado para facilitar a leitura rápida)
        printf("1. Adicao\t\t5. Raiz Quadrada\n");
        printf("2. Subtracao\t\t6. Porcentagem\n");
        printf("3. Multiplicacao\t7. Potenciacao\n");
        printf("4. Divisao\t\t8. Sair\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

        printf("Escolha uma opcao: ");
        
        // Validação da entrada: verifica se o usuário digitou um número
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado para evitar loop infinito
            SLEEP_MS(2000);
            continue; 
        }

        // ESTRUTURA DE DECISÃO: Define a operação com base na escolha
        switch(opcao) {
            
            case 1: // ADIÇÃO
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 + num2;
                printf("Resultado: %.2lf\n", resultado);
                break;
            
            case 2: // SUBTRAÇÃO
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 - num2;
                printf("Resultado: %.2lf\n", resultado);
                break;
            
            case 3: // MULTIPLICAÇÃO
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 * num2;
                printf("Resultado: %.2lf\n", resultado);
                break;
            
            case 4: // DIVISÃO (Com tratamento de erro matemático)
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf\n", resultado);
                } else {
                    printf("Erro: Nao e possivel dividir por zero!\n");
                }
                break;
            
            case 5: // RAIZ QUADRADA (Uso da math.h)
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    resultado = sqrt(num1);
                    printf("Raiz Quadrada: %.2lf\n", resultado);
                } else {
                    printf("Erro: Numeros negativos nao possuem raiz real!\n");
                }
                break;
            
            case 6: // PORCENTAGEM
                printf("Digite o valor total e a porcentagem (Ex: 500 10): ");
                scanf("%lf %lf", &num1, &num2);
                resultado = (num1 * num2) / 100;
                printf("%.2lf%% de %.2lf e: %.2lf\n", num2, num1, resultado);
                break;
            
            case 7: // POTENCIAÇÃO (Uso da math.h)
                printf("Digite a base e o expoente: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = pow(num1, num2);
                printf("Resultado: %.2lf\n", resultado);
                break;
            
            case 8: // SAÍDA
                printf("Encerrando o sistema...\n");
                SLEEP_MS(1000);
                break;
            
            default: // TRATAMENTO DE OPÇÃO INEXISTENTE
                printf("Opcao invalida! Escolha entre 1 e 8.\n");
        }

        // Pausa o programa para o usuário ler o resultado antes de limpar a tela novamente
        if (opcao != 8) {
            printf("\nPresione ENTER para continuar...");
            getchar(); // Captura o Enter pendente do scanf
            getchar(); // Aguarda o novo Enter
        }
      
    } while (opcao != 8); // Condição de saída: o loop para quando opcao for 8

    return 0; // Sucesso na execução
}
