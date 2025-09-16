#include <stdio.h>

int main(){
    ///O código pede para que o usuário insira um número
    int multiplication;
    
    printf("Type one numbe see your multiplication table: ");
    scanf("%d", &multiplication);
    
    ///FOR e utilizado para o usuário ter o resultado de 1 a 10
    ///Conforme o número e inserido pelo usuário através do (printf)
    int result[10];
    
    for(int i = 0; i < 10; i ++){
        result[i] = (i + 1) * multiplication;
        
    }
    for(int i = 0; i < 10; i ++){
        printf("%d x %d = %d\n", multiplication, (i + 1), result[i]);
    }
    
    
    
    return 0;
}


