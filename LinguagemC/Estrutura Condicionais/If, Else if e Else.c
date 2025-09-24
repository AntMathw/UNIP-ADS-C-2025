 #include <stdio.h>
 int main() {
    int a = 3;
    if (a > 5) {
        printf("a é maior que 5\n");
    } else {
        printf("a não é maior que 5\n");
    }
    return 0;
 

#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O numero e positivo.\n");
    } else if (numero < 0) {
        printf("O numero e negativo.\n");
    } else {
        printf("O numero e zero.\n");
    }

    return 0;
}