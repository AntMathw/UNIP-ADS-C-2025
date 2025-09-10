#include <stdio.h>
#include <string.h>

int main() {

    void lerstring(char * buffer, int tamanho){
        if(fgets(buffer,tamanho,stdin) != NULL){
            buffer[strcspn(buffer,"\n") = '\0';
        }
    }
    
    

    return 0;
}
