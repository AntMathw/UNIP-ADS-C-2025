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
