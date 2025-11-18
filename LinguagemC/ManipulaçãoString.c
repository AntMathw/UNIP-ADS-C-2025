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

#include <stdio.h>
#include <string.h>

// Função customizada para inverter uma string (não há uma função padrão "strrev" em todos os compiladores C)
void inverterString(char *str) {
    int comprimento = strlen(str);
    int i, j;
    char temp;

    // Percorre a string da primeira metade até o meio, trocando os caracteres
    for (i = 0, j = comprimento - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    // 1. Declaração e Inicialização de Strings
    char str1[50] = "Programacao em C e muito poderosa!";
    char str2[50] = "Manipulacao de strings.";
    char str3[50]; // String de destino para cópia
    char str4[50] = "Ola Mundo";
    char str5[50] = "Ola C!";
    int resultado_comparacao;

    printf("--- Demonstração de Manipulação de Strings em C ---\n\n");

    // 2. Comprimento da String (strlen)
    // Retorna o número de caracteres na string (excluindo o '\0')
    size_t comprimento = strlen(str1);
    printf("1. Comprimento de \"%s\": %zu\n", str1, comprimento);

    // 3. Cópia de String (strcpy)
    // Copia o conteúdo de str1 para str3
    strcpy(str3, str1);
    printf("2. Após a cópia (strcpy), str3 é: %s\n", str3);

    // 4. Concatenação de Strings (strcat)
    // Anexa o conteúdo de str2 ao final de str1
    strcat(str1, " "); // Adiciona um espaço antes de concatenar
    strcat(str1, str2);
    printf("3. Após a concatenação (strcat), str1 é: %s\n", str1);

    // 5. Comparação de Strings (strcmp)
    // Compara str4 e str5 lexicograficamente (ordem alfabética)
    resultado_comparacao = strcmp(str4, str5);

    if (resultado_comparacao == 0) {
        printf("4. Comparação (strcmp): As strings \"%s\" e \"%s\" são iguais.\n", str4, str5);
    } else if (resultado_comparacao < 0) {
        printf("4. Comparação (strcmp): \"%s\" vem antes de \"%s\". (Resultado: %d)\n", str4, str5, resultado_comparacao);
    } else { // resultado_comparacao > 0
        printf("4. Comparação (strcmp): \"%s\" vem depois de \"%s\". (Resultado: %d)\n", str4, str5, resultado_comparacao);
    }

    // 6. Busca de Substring (strstr)
    // Procura a primeira ocorrência da substring "muito" dentro de str3
    char *busca_substring = strstr(str3, "muito");
    if (busca_substring != NULL) {
        printf("5. Substring (strstr): 'muito' encontrado em: %s\n", busca_substring);
    } else {
        printf("5. Substring (strstr): Substring não encontrada.\n");
    }

    // 7. Inversão de String (Função Customizada)
    char str_reversa[50] = "Exemplo";
    printf("6. String original para inversão: %s\n", str_reversa);
    inverterString(str_reversa);
    printf("   String invertida: %s\n", str_reversa);

    return 0;
}
