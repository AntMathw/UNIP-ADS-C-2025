#include <stdio.h>
#define l 3
#define c 3

///Matrizes usando estrutura de repetição FOR
int main(){
    
    int matrices[l][c];
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j++){
            scanf("%d", &matrices[i][j]);
        }
    }
    
    
    
    return 0;
}

///Cálculo das Matrizes 3x3 A e B

#include <stdio.h>

#define l 3
#define c 3

int main(){
    
    ///1. PASSO = Criar três matrizes
    
    int matriz_a[l][c];
    int matriz_b[l][c];
    int resultado[l][c];
    
    ///2. PASSO = Valor da Primeira matriz
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j ++){
            printf("Digite um valor A[%d][%d]: ", i, j);
            scanf("%d", &matriz_a[i][j]);
            
        }
    }
    printf("\n");
    
    ///3. PASSO = Valor da Segunda Matriz
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j ++){
            printf("Digite outro valor B[%d][%d]: ", i, j);
            scanf("%d", &matriz_b[i][j]);
        }
    }
    printf("\n");
    
    ///4. PASSO = Cálculo das matrizes A e B
    
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j ++){
            resultado[i][j] = matriz_a[i][j] + matriz_b[i][j];
            
        }
    }
    
    ///5. PASSO = Imprimir a soma na tela no formato linhas e colunas
    printf("------RESULTADO DA SOMA DAS MATRIZES------\n");
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j ++){
            printf("%5d", resultado[i][j]);

        }
        
        printf("\n");
    }
    
    return 0;
}
