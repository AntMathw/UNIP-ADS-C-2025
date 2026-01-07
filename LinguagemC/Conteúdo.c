/// Cálculo do Indíce de Massal Corporal

#include <stdio.h>
#include <math.h>

float calculo(float massa, float altura);

int main(){
    float massa, altura, imc;
    
    printf("Qual é sua massa?: ");
    scanf("%f", &massa);
    printf("Qual sua altura?: ");
    scanf("%f", &altura);
    
    imc = calculo(massa, altura);
    if(imc < 18.5 ){
        printf("Você está com baixo índice de massa corporal");
    }else if (imc >= 18.5 && imc <= 24.9){
        printf("Você está com massa corporal estável");
    }else if (imc >= 25 && imc <= 30){
        printf("Você está no começo de obesidade");
    }else if (imc >= 30 && imc <= 35){
        printf("Você em obesidade em grau 1");
    }else if (imc >= 35 && imc <= 40){
        printf("Você em está em obesidade grau 2");
    }else{
        printf("Você está obesidade grau 3");
    }
    
return 0;
}

float calculo(float massa, float altura){
    float calculando = pow(altura, 2);
    float divisao = massa / calculando;
    
    
    
    return divisao;
}

#include <stdio.h>;

int main(){
    float distancia = 438;
    float tempo = 6;
    float velocidade = distancia / tempo;
    printf("%.2f", velocidade);
return 0;
}

//Calculo da Média

#include <stdio.h>;

float calc_media(float p1, float p2);

int main(){
    float prova1, prova2, média;
    printf("Digite o valor da primeira prova");
    scanf("%f", &prova1);
    printf("Digite o valor da segunda prova");
    scanf("%f", &prova2);
    média = calc_media(prova1, prova2);
    printf("O resultado da média é: %.2f", média);
    return 0;
}

float calc_media(float p1, float p2){
    float média;
    média = (p1 + p2) / 2.0;
    return média;
    
}

//Outra forma de calcular média

#include <stdio.h>

int main(){
    float prova1, prova2, média;
    scanf("%f", &prova1);
    scanf("%f", &prova2);
    média = (prova1 + prova2) / 2.0;
    printf("%.2f", média);
    
return 0;

}

// Multiplicação 

#include <stdio.h>

int main(){
    int valor, multiplicando, resultado;
    printf("Digite um valor: ");
    scanf("%i", &valor);
    printf("Digite outro valor: ");
    scanf("%i", &multiplicando);
    resultado = (valor * multiplicando);
    printf("O resultado é: %i", resultado);

    
return 0;
    
}

//Outra forma de multiplicar

#include <stdio.h>

int calc_multiplicando(int valor, int multiplicando);

int main(){
    int valor, multiplicando, resultado;
    printf("Digite o primeiro valor: ");
    scanf("%i", &valor);
    printf("digite o segundo valor: ");
    scanf("%i", &multiplicando);
    resultado = calc_multiplicando(valor, multiplicando);
    printf("O resultado é: %i", resultado);
    
return 0;

}

int calc_multiplicando(int valor, int multiplicando){
    int resultado;
    resultado = (valor * multiplicando);
    return resultado;
    
}

//Raiz quadrada, somatório e divisão

#include <stdio.h>
#include <math.h>

float calcular(float numero_raiz, float numero_soma);

int main() {
    float numero_raiz, numero_soma, resultado;

    printf("Digite um número para a raiz quadrada: ");
    scanf("%f", &numero_raiz);

    printf("Digite um número para somar: ");
    scanf("%f", &numero_soma);

    resultado = calcular(numero_raiz, numero_soma);

    printf("O resultado é: %f\n", resultado);

    return 0;
}

float calcular(float numero_raiz, float numero_soma) {
    float raiz = sqrt(numero_raiz);
    float soma = raiz + numero_soma;
    float resultado = soma / 2.0;
    return resultado;
}

///Cálculo da área

#include <stdio.h>
#define pi 3.1416
 int main(){
     ///A = pi(3,1416...) * raiz quadrada(x / 2)
     float r, a;
     scanf("%f", &r);
     a = pi * (r * r);
     printf("%.2f", a);
     
     
     return 0;
 }

///Tabuada utilizando estrutura While

#include <stdio.h>


int main(){
    int cont = 0;
    int limite;
    printf("Escolha um número e veja sua tabuada: ");
    scanf("%i", &cont);
    
    while (cont <= 10){
        limite = 0;
        while (limite <= 10){
            printf("%d x %d = %d\n", cont, limite, cont * limite);
            limite ++;
        }
return 0;
    }
    

}

///Tabuada utilizando o DEFINE

#include <stdio.h>
#define LIMITE 10

#include <stdio.h>
#define LIMITE 10

int main() {
    int i;
    int limite;

    printf("Escolha um número e veja sua tabuada: ");
    scanf("%d", &i);

    limite = 0;
    while (limite <= LIMITE) {
        printf("%d x %d = %d\n", i, limite, i * limite);
        limite++;
    }

    return 0;
}

///Tabuada em estrutura FOR

#include <stdio.h>
#define LIMITE 10

int main(){
    int n, c = 0;
    printf("Número da tabuada: ");
    scanf("%d", &n);
    for (int c = 1; c <= LIMITE; c++){
        printf("%d x %d = %d\n", n, c, (n * c));
        
    }
    return 0;
}

///Recursividade Fatorial

#include <stdio.h>

int fatorial(int n) {
    if (n == 0 || n == 1)  // Caso base
        return 1;
    else
        return n * fatorial(n - 1);  
}

int main() {
    int num = 6;
    printf("Fatorial de %d é %d\n", num, fatorial(num));
    return 0;
}

//Formulário
#include <stdio.h>
#include <string.h>



int main(){

    char nome1[51];
    char nome2[51];
    
    printf("Digite o seu nome: ");
    scanf("%50s", &nome1);
    printf("Nome: %s\n", nome1);
    getchar();
    
    printf("Digite o segundo nome: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2,"\n")] = '\0';
    printf("Nome: %s\n", nome2);
    
    
    
    
    return 0;
}


//Outra maneira de fazer um Formulário

#include <stdio.h>
#include <string.h>

int main() {

    char nome1[51];
    char sobrenome[51];
    char datanascimento[11];  
    char email[100];
    char celular[12];

    printf("FORMULÁRIO\n\n");

    printf("Digite o seu nome: \n");
    scanf("%50s", nome1);   
    printf("Nome: %s\n", nome1);
    getchar();

    printf("Digite o sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';
    printf("Sobrenome: %s\n", sobrenome);

    printf("Digite sua data de nascimento DD/MM/AAAA: ");
    fgets(datanascimento, sizeof(datanascimento), stdin);  
    datanascimento[strcspn(datanascimento, "\n")] = '\0';
    printf("Nascimento: %s\n", datanascimento);
    getchar();

    printf("Digite seu e-mail: ");
    fgets(email, sizeof(email), stdin);  
    email[strcspn(email, "\n")] = '\0';
    printf("E-mail: %s\n", email);
    getchar();

    printf("Digite seu número de celular (+55): ");
    fgets(celular, sizeof(celular), stdin);  
    celular[strcspn(celular, "\n")] = '\0';
    printf("Celular: %s\n", celular);  
    getchar();

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    // Declara e inicializa uma string.
    // O compilador adiciona o '\0' automaticamente.
    char saudacao[] = "Olá, mundo!";

    // Declara um array de caracteres e copia uma string para ele.
    char nome[20];
    strcpy(nome, "Maria");

    // Imprime as strings.
    printf("Saudação: %s\n", saudacao);
    printf("Nome: %s\n", nome);

    // Calcula o comprimento da string (não conta o '\0').
    int tamanho = strlen(saudacao);
    printf("O tamanho da saudação é: %d\n", tamanho);

    return 0;
}

#include <stdio.h>

int main() {
    float numero1, numero2, resultado_divisao, resultado_multiplicacao;

    // Solicita os dois números ao usuário
    printf("Digite o primeiro numero: ");
    scanf("%f", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%f", &numero2);

    // Verifica se o segundo número é zero para evitar divisão por zero
    if (numero2 == 0) {
        printf("Erro: Nao e possivel dividir por zero.\n");
        return 1; // Retorna um código de erro
    }

    // Realiza a divisão
    resultado_divisao = numero1 / numero2;

    // Realiza a multiplicação do resultado da divisão por outro número (neste exemplo, 2)
    // Você pode substituir o 2 por qualquer outro número que desejar.
    resultado_multiplicacao = resultado_divisao * 2;

    // Exibe os resultados
    printf("O resultado da divisao e: %.2f\n", resultado_divisao);
    printf("O resultado da multiplicacao (do resultado da divisao por 2) e: %.2f\n", resultado_multiplicacao);

    return 0; // Indica que o programa foi executado com sucesso
}

#include <stdio.h>

// Função principal onde a execução do programa começa
int main() {
    // 1. Declaração de variáveis inteiras (integers)
    int numero1 = 15;
    int numero2 = 7;
    int soma;

    // Mensagem de introdução
    printf("--- Exemplo de Código Simples em C ---\n\n");

    // 2. Realização da operação de soma
    soma = numero1 + numero2;

    // 3. Impressão dos resultados na tela (saída)
    printf("O primeiro número é: %d\n", numero1);
    printf("O segundo número é: %d\n", numero2);
    printf("A soma dos dois números é: %d\n", soma);

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}

#include <stdio.h>

// Função principal
int main() {
    // Declaração das variáveis
    int n;          // O número fornecido pelo usuário
    long long fatorial = 1; // Variável para armazenar o resultado. Usa-se 'long long' para suportar fatoriais maiores.
    int i;          // Contador do loop

    printf("--- Calculadora de Fatorial em C ---\n\n");

    // Solicita que o usuário insira um número
    printf("Digite um número inteiro positivo: ");

    // Lê o número fornecido pelo usuário
    if (scanf("%d", &n) != 1) {
        printf("Erro de entrada. Por favor, insira um número inteiro.\n");
        return 1; // Retorna 1 para indicar erro
    }

    // Verifica se o número é não-negativo (o fatorial é definido para n >= 0)
    if (n < 0) {
        printf("O fatorial não é definido para números negativos.\n");
    } else if (n == 0) {
        // Fatorial de 0 é 1
        printf("O fatorial de 0 é 1.\n");
    } else {
        // Calcula o fatorial usando um loop 'for'
        for (i = 1; i <= n; ++i) {
            // Multiplica o resultado pelo contador em cada iteração
            fatorial *= i;
        }

        // Imprime o resultado
        printf("O fatorial de %d é: %lld\n", n, fatorial);
    }

    return 0; // Retorna 0 para indicar sucesso
}

#include <stdio.h>

int main() {
    // 1. Declaração de Variáveis
    // float = números decimais (dinheiro)
    // int = números inteiros (pessoas, porcentagem)
    float valor_conta, valor_servico, total_final, valor_por_pessoa;
    int porcentagem_garcom, numero_pessoas;

    printf("--- Calculadora de Racha Conta (C) ---\n\n");

    // 2. Entrada de Dados (scanf)
    printf("Qual o valor total da conta? R$ ");
    // O '&' é necessário para dizer ONDE guardar o valor na memória
    scanf("%f", &valor_conta); 

    printf("Qual a %% do garcom? (ex: 10): ");
    scanf("%d", &porcentagem_garcom);

    printf("Quantas pessoas vao dividir? ");
    scanf("%d", &numero_pessoas);

    // 3. Processamento (Multiplicação e Divisão)
    
    // IMPORTANTE: Em C, se dividirmos int por int (ex: 10/100), o resultado é 0.
    // Por isso escrevemos 100.0 para forçar uma divisão decimal.
    valor_servico = valor_conta * (porcentagem_garcom / 100.0);
    
    total_final = valor_conta + valor_servico;
    
    // Verificação simples para evitar divisão por zero
    if (numero_pessoas > 0) {
        valor_por_pessoa = total_final / numero_pessoas;

        // 4. Saída de Dados (printf)
        // %.2f significa: mostre um float com 2 casas decimais
        printf("\n--- Resultado ---\n");
        printf("Valor do servico: R$ %.2f\n", valor_servico);
        printf("Total com servico: R$ %.2f\n", total_final);
        printf("------------------------------\n");
        printf("CADA UM PAGA: R$ %.2f\n", valor_por_pessoa);
    } else {
        printf("\nErro: O numero de pessoas deve ser maior que zero.\n");
    }

    return 0;
}

#include <stdio.h>

// Definimos uma função para realizar o cálculo
double calcular_forca(double massa, double aceleracao) {
    // F = m * a
    double forca = massa * aceleracao;
    return forca;
}

int main() {
    // 1. Declaração das variáveis
    double massa_kg;        // Variável para armazenar a massa em kg
    double aceleracao_ms2;  // Variável para armazenar a aceleração em m/s^2
    double forca_newton;    // Variável para armazenar o resultado da força

    // 2. Coleta de dados (Entrada)
    printf("--- Cálculo da Segunda Lei de Newton (F = m * a) ---\n");
    
    // Solicita a massa
    printf("Digite o valor da massa (em kg): ");
    // O especificador %lf é usado para ler um double
    if (scanf("%lf", &massa_kg) != 1) {
        printf("Erro na leitura da massa.\n");
        return 1; // Retorna código de erro
    }
    
    // Solicita a aceleração
    printf("Digite o valor da aceleração (em m/s^2): ");
    if (scanf("%lf", &aceleracao_ms2) != 1) {
        printf("Erro na leitura da aceleração.\n");
        return 1; // Retorna código de erro
    }

    // 3. Processamento (Cálculo)
    forca_newton = calcular_forca(massa_kg, aceleracao_ms2);

    // 4. Exibição do resultado (Saída)
    printf("\n--- Resultado do Cálculo ---\n");
    printf("Massa (m): %.2lf kg\n", massa_kg);
    printf("Aceleração (a): %.2lf m/s^2\n", aceleracao_ms2);
    printf("Força (F): %.2lf Newtons (N)\n", forca_newton);
    printf("----------------------------\n");

    return 0; // Retorna 0 para indicar sucesso
}

#include <stdio.h>

int main() {
    // Declaramos uma "string" (vetor de caracteres) para armazenar o nome da cor
    char cor[20];

    printf("Ola! Qual e a sua cor favorita? ");
    
    // O %s serve para ler uma palavra (string)
    // O limite [19] evita que o usuario digite algo maior que o espaco reservado
    scanf("%19s", cor);

    printf("\nQue legal! %s tambem e uma cor muito bonita.\n", cor);

    return 0;
}

#include <stdio.h>

/**
 * Programa simples para calcular a média de dois números.
 * Demonstra o uso de variáveis, entrada de dados (scanf) e saída (printf).
 */
int main() {
    // Declaração de variáveis
    float numero1, numero2, media;

    printf("--- Calculadora de Média Simples ---\n\n");

    // Entrada de dados
    printf("Introduza o primeiro número: ");
    scanf("%f", &numero1);

    printf("Introduza o segundo número: ");
    scanf("%f", &numero2);

    // Processamento
    media = (numero1 + numero2) / 2;

    // Saída de resultados
    // %.2f limita a exibição a duas casas decimais
    printf("\nA média entre %.2f e %.2f é: %.2f\n", numero1, numero2, media);

    // Condicional simples para feedback
    if (media >= 9.5) {
        printf("Resultado: Aprovado!\n");
    } else {
        printf("Resultado: Necessita de melhoria.\n");
    }

    return 0;
}

