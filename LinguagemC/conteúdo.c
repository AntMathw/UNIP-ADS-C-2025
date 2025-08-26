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
