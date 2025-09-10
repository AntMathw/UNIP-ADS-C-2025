#include <stdio.h>
#include <string.h> 

void ler_string(char * buffer, int tamanho){
    if (fgets(buffer, tamanho, stdin) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

int main(){
    char nome[20];
    ler_string(nome, sizeof(nome)); 
    printf("Nome: %s", nome);
    return 0; 
}
