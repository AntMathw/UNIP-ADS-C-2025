#include <stdio.h>
#include <stdlib.h>  // Para malloc e free

int main() {
    int vet[10];  // Vetor alocado estaticamente (na stack)

    int *ptr = (int*) malloc(10 * sizeof(int));  // Alocação dinâmica
    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Exemplo: preencher o vetor com valores de 1 a 10
    for (int i = 0; i < 10; i++) {
        p
