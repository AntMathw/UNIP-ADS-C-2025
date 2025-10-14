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

//SOMA DOS ELEMENTOS DE ALOCAÇÃO DE MEMÓRIA

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &t);
    
    if(t > 0){
        int * ptr = (int*) malloc(t * sizeof(int));
        for(int i = 0; i < t; i++){
            printf("Informe o valor da posição %d: ", i);
            scanf("%d", &ptr[i]);
            
        }
        int soma = 0;
        for(int i = 0; i < t; i++){
            soma += ptr[i];
        }
        printf("A soma dos valores informados é %d", soma);
        free(ptr);
        ptr = NULL;
    }else{
        printf("O valor informado deve ser maior que 0");
        
    }
    
    return 0;    
        
    
}
