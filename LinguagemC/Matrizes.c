#include <stdio.h>
#define l 3
#define c 3

///Matrizes usando estrutura de repetição FOR
int main(){
    
    int matrices[l][c];
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j++){
            scanf("%d", &matrices[i][j]);
        }
    }
    
    
    
    return 0;
}


