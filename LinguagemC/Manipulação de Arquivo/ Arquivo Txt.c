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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho máximo da linha a ser lida
#define MAX_LINHA 256
// Nome do arquivo
#define NOME_ARQUIVO "exemplo_simples_dx.txt"

int main() {
    FILE *arquivo; // Ponteiro para a estrutura de arquivo
    char linha[MAX_LINHA]; // Buffer para armazenar as linhas lidas
    int num_linha = 1;

    // ----------------------------------------------------
    // 1. CRIAR E ESCREVER NO ARQUIVO (Modo "w" - write)
    // ----------------------------------------------------
    printf("1. Criando e escrevendo no arquivo '%s'...\n", NOME_ARQUIVO);

    // Tenta abrir o arquivo no modo de escrita ("w")
    arquivo = fopen(NOME_ARQUIVO, "w");

    // Checa se houve erro ao abrir o arquivo
    if (arquivo == NULL) {
        perror("   -> ERRO: Não foi possível abrir o arquivo para escrita");
        return 1; // Retorna código de erro
    }

    // Escreve duas linhas no arquivo
    fprintf(arquivo, "Dados de entrada: uma linha escrita em C.\n");
    fprintf(arquivo, "Outra linha com informações essenciais (em C).\n");

    // Fecha o arquivo após a escrita
    fclose(arquivo);
    printf("   -> Escrita concluída e arquivo fechado.\n");

    // ----------------------------------------------------
    // 2. LER O CONTEÚDO DO ARQUIVO (Modo "r" - read)
    // ----------------------------------------------------
    printf("\n2. Lendo o conteúdo do arquivo '%s'...\n", NOME_ARQUIVO);

    // Tenta abrir o arquivo no modo de leitura ("r")
    arquivo = fopen(NOME_ARQUIVO, "r");

    // Checa se houve erro ao abrir o arquivo (embora improvável após a escrita)
    if (arquivo == NULL) {
        perror("   -> ERRO: Não foi possível abrir o arquivo para leitura");
        return 1;
    }

    printf("   -> Conteúdo lido:\n");
    // Lê o arquivo linha por linha até o fim (fgets retorna NULL no fim)
    while (fgets(linha, MAX_LINHA, arquivo) != NULL) {
        // O fgets armazena a quebra de linha ('\n'). 
        // Para uma exibição mais limpa, removemos ela se for o último caractere.
        size
