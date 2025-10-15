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
