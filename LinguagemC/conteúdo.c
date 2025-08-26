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
