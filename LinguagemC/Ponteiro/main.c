//Ponteiro básico

#include <stdio.h>

int main(){
    
    int var = 10;
    
    int *ptr;
    
    ptr = &var;
    
    printf("var = %d[%p]\n\n", var, (void*)&var);
    printf("*ptr = %d[%p][%p]\n", *ptr, (void*)ptr,(void*)&ptr);
    
    
    return 0;
}

#include <stdio.h>

void trocarValores(int *ptrA, int *ptrB) {
    // Declara uma variável temporária para armazenar o valor de *ptrA.
    // Lembre-se: *ptrA é o valor contido no endereço apontado por ptrA.
    int temp = *ptrA;
    
    // Altera o valor no endereço de 'a' para o valor do endereço de 'b'.
    *ptrA = *ptrB;
    
    // Altera o valor no endereço de 'b' para o valor temporário (valor original de 'a').
    *ptrB = temp;
}

int main() {
    // -------------------------------------------------------------------------
    // 1. Conceito Básico: Declaração, Endereço de Memória e Desreferenciação
    // -------------------------------------------------------------------------
    printf("--- Conceito Básico e Desreferenciação ---\n");
    
    int numero = 42;
    // Declaração de um ponteiro para um inteiro
    int *ptrNumero; 

    // O ponteiro 'ptrNumero' armazena o endereço de memória de 'numero' (& é o operador de endereço)
    ptrNumero = &numero; 

    printf("Valor da variável 'numero': %d\n", numero);
    printf("Endereço de 'numero' (&numero): %p\n", &numero);
    printf("Valor do ponteiro 'ptrNumero' (Endereço armazenado): %p\n", ptrNumero);
    // Desreferenciação: acessa o valor no endereço apontado (* é o operador de desreferenciação)
    printf("Valor apontado por 'ptrNumero' (*ptrNumero): %d\n", *ptrNumero);

    // Alterando o valor da variável através do ponteiro
    *ptrNumero = 99;
    printf("\nNovo valor de 'numero' após alteração via ponteiro: %d\n", numero);
    
    printf("\n");
    
    // -------------------------------------------------------------------------
    // 2. Ponteiros e Arrays (Aritmética de Ponteiros)
    // -------------------------------------------------------------------------
    printf("--- Ponteiros e Aritmética de Ponteiros ---\n");
    
    int vetor[5] = {10, 20, 30, 40, 50};
    // O nome de um array (vetor) já é um ponteiro para o primeiro elemento.
    int *ptrVetor = vetor; // É o mesmo que: int *ptrVetor = &vetor[0];

    printf("Primeiro elemento do vetor (*ptrVetor): %d\n", *ptrVetor);
    
    // Aritmética de ponteiros: (ptrVetor + 2) avança 2 posições (2 * sizeof(int))
    printf("Terceiro elemento (vetor[2] ou *(ptrVetor + 2)): %d\n", *(ptrVetor + 2)); 
    
    // Mover o ponteiro para o próximo elemento
    ptrVetor++; 
    printf("Segundo elemento após incremento do ponteiro (*ptrVetor): %d\n", *ptrVetor); 

    printf("\n");

    // -------------------------------------------------------------------------
    // 3. Uso Prático: Função de Troca de Valores (Passagem por Referência)
    // -------------------------------------------------------------------------
    printf("--- Uso Prático: Passagem por Referência ---\n");
    
    int x = 100;
    int y = 200;

    printf("Antes da troca: x = %d, y = %d\n", x, y);

    // Chamamos a função passando os endereços de x e y
    trocarValores(&x, &y);

    printf("Depois da troca: x = %d, y = %d\n", x, y);
    
    return 0;
}

//Estado de um ponteiro

#include <stdio.h>

int main() {
    // 1. Declaração de uma variável inteira e sua inicialização
    int valorOriginal = 42;

    // 2. Declaração de um ponteiro para inteiro (int *)
    // O asterisco (*) indica que 'ptr' é um ponteiro, e não uma variável comum.
    int *ptr;

    // 3. Atribuindo o endereço de memória da variável 'valorOriginal' ao ponteiro 'ptr'
    // O operador '&' (e-comercial) é o operador "endereço de" (address-of).
    ptr = &valorOriginal;

    printf("--- Estado Inicial ---\n");
    printf("Valor da variavel original (valorOriginal): %d\n", valorOriginal);
    printf("Endereco de memoria de 'valorOriginal': %p\n", &valorOriginal);
    printf("Conteudo do ponteiro 'ptr' (o endereco armazenado): %p\n", ptr);

    // 4. Acessando o valor da variável através do ponteiro (Desreferenciação)
    // O operador '*' (asterisco, neste contexto) é o operador "valor em" (dereference).
    // Ele acessa o dado que está no endereço armazenado pelo ponteiro.
    printf("\n--- Acesso via Ponteiro ---\n");
    printf("Valor acessado via ponteiro (*ptr): %d\n", *ptr);

    // 5. Modificando o valor da variável original usando o ponteiro
    // Estamos dizendo: "Coloque o valor 99 no local apontado por 'ptr'".
    *ptr = 99;

    printf("\n--- Apos a Modificacao com Ponteiro (*ptr = 99) ---\n");
    printf("Novo valor acessado via ponteiro (*ptr): %d\n", *ptr);
    printf("Novo valor da variavel original (valorOriginal): %d\n", valorOriginal);

    // Observacao: A modificacao via ponteiro alterou diretamente a variavel original.
    if (valorOriginal == 99) {
        printf("\nSucesso! O ponteiro modificou a variavel original diretamente.\n");
    }

    return 0;
}
