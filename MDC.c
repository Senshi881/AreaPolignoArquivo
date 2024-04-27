//Implemente uma função para calcular o MDC de dois números passados como parâmetro.
#include <stdlib.h>
#include <stdio.h>

int calculaMDC(int a, int b);

int main(){
    int a = 20;
    int b = 20;

    calculaMDC(a, b);
    int valor = calculaMDC(a, b);
    printf("\nMDC = %d", valor);

    return 0;
}

int calculaMDC(int a, int b){
    int resto;

    do {
        resto = a % b;
        a = b;
        b = resto;
    } while(b != 0);

    return a;
}