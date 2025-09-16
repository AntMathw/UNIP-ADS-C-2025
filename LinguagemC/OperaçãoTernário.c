#include <stdio.h>

int main(){
    
    ///Operação Ternário (n1 > n2) 'v(Verdadeira)' 'f(Falso)'
    int n1 = 3;
    int n2 = 2;
    char res;
    
    res = (n1 < n2)?'v':'f';
    printf("Operação é %s", &res);
    
    return 0;
}


