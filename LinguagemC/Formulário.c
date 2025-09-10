#include <stdio.h>
#include <string.h>

int main() {

    char nome1[51];
    char sobrenome[51];
    char datanascimento[11];  
    char email[100];
    char celular[16];

    printf("FORMULÁRIO\n\n");

    printf("Digite o seu nome: \n");
    scanf("%50s", nome1);   
    

    printf("Digite o sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';


    printf("Digite sua data de nascimento DD/MM/AAAA: ");
    fgets(datanascimento, sizeof(datanascimento), stdin);  
    datanascimento[strcspn(datanascimento, "\n")] = '\0';
    

    printf("Digite seu e-mail: ");
    fgets(email, sizeof(email), stdin);  
    email[strcspn(email, "\n")] = '\0';


    printf("Digite seu número de celular (+55): ");
    fgets(celular, sizeof(celular), stdin);  
    celular[strcspn(celular, "\n")] = '\0';
     
    strcat(nome1, " ");
    strcat(nome1, sobrenome);
    printf("Nome: %s\n", nome1);
    printf("Sobrenome: %s\n", sobrenome);
    printf("Data Nascimento AA/MM/AAAA: %d\n", datanascimento);
    printf("E-mail: %s\n", email);
    printf("Celular: %d\n", celular);
    
    

    return 0;
}
