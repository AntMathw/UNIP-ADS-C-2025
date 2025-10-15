#include <stdio.h>

int main(){

    FILE *file = fopen("Arquivo.txt", "r");


    if (file == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    char buffer [100];
    if(fgets(buffer, sizeof(buffer), file) != NULL){
        printf("Conteúdo do arquivo: %s\n", buffer);

    }
    fclose(file);
    file = NULL;

    return 0;

}

// Arquivo: manipulacao_arquivo.c
#include <stdio.h>
#include <stdlib.h> // Para usar a função exit()

#define FILENAME "exemplo.txt"

int main() {
    FILE *filePointer; // Ponteiro para manipular o arquivo

    // --- PARTE 1: ESCREVER NO ARQUIVO (MODO "w" - write/escrita) ---

    printf("--- Escrevendo no arquivo %s ---\n", FILENAME);

    // Abre o arquivo no modo de escrita ("w").
    // Se o arquivo não existir, ele é criado. Se existir, seu conteúdo é apagado.
    filePointer = fopen(FILENAME, "w");

    // Verifica se a abertura foi bem-sucedida
    if (filePointer == NULL) {
        perror("Erro ao abrir/criar o arquivo para escrita");
        return 1; // Retorna código de erro
    }

    // Escreve duas linhas de texto no arquivo
    fprintf(filePointer, "Esta é a primeira linha de teste.\n");
    fprintf(filePointer, "Esta é a segunda linha, escrita em C.\n");

    // Fecha o arquivo. Isso é crucial para garantir que os dados sejam salvos.
    fclose(filePointer);
    printf("Dados escritos com sucesso e arquivo fechado.\n\n");

    // --- PARTE 2: LER DO ARQUIVO (MODO "r" - read/leitura) ---

    printf("--- Conteúdo lido do arquivo %s ---\n", FILENAME);

    // Abre o arquivo no modo de leitura ("r")
    filePointer = fopen(FILENAME, "r");

    // Verifica se a abertura foi bem-sucedida (o que só falharia se o arquivo fosse apagado entre as operações)
    if (filePointer == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    // Buffer para armazenar cada linha lida do arquivo
    char buffer[256];

    // Lê o arquivo linha por linha até o final (EOF - End Of File)
    printf("======================================\n");
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        // Imprime a linha lida no console
        printf("%s", buffer);
    }
    printf("======================================\n");

    // Fecha o arquivo após a leitura
    fclose(filePointer);
    printf("\nLeitura do arquivo concluída.\n");

    return 0; // Sucesso
}
