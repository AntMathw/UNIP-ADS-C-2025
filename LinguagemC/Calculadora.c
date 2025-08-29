///Calculado em Linguagem C

#include <stdio.h>
#define LIMITE 10

int main(){
    char operacao;
        int num1, num2; 
        printf("Informe o primeiro número: ");
        scanf("%i", &num1);
        printf("Informe o segundo número: ");
        scanf("%i", &num2);
        printf("Digite umas das operações: ");
        scanf(" %c", &operacao);
        
        switch(operacao){
            case '+': printf("%d + %d = %d\n", num1 , num2, num1 + num2); break;
            case '-': printf("%d - %d = %d\n", num1, num2, num1 - num2); break;
            case '/': printf("%d / %d = %d\n", num1, num2, num1 / num2); break;
            case '*': printf("%d * %d = %d\n", num1, num2, num1 * num2); break;
            default: printf("Operação Inválida");
        }
    
    return 0;
}
