#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Ola, Mundo!";
    char str2[50];
    char str3[50] = " Bem-vindo ao C.";

    // 1. Copiando uma string (strcpy)
    strcpy(str2, str1);
    printf("String copiada (str2): %s\n", str2);

    // 2. Concatenando strings (strcat)
    strcat(str1, str3);
    printf("String concatenada (str1): %s\n", str1);

    // 3. Obtendo o tamanho de uma string (strlen)
    int tamanho = strlen(str1);
    printf("Tamanho da string (str1): %d\n", tamanho);

    // 4. Comparando strings (strcmp)
    char str4[50] = "Ola, Mundo! Bem-vindo ao C.";
    int comparacao = strcmp(str1, str4);
    if (comparacao == 0) {
        printf("As strings str1 e str4 sao iguais.\n");
    } else {
        printf("As strings str1 e str4 sao diferentes.\n");
    }

    return 0;
}