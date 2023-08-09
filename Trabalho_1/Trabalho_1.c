#include <stdio.h>
#include <stdlib.h>


int main(){

    int val;
    int bin[4];
    int cont;

    printf("Escolha o valor de 0 a 31 para ser convertido: ");
    scanf("%d", &val);

    if (val >= 0 && val <= 31) {
        for (cont = 4; cont >= 0; cont--) {
            if (val % 2 == 0) {
                bin[cont] = 0;
                val = val/2;
            }
            else {
                bin[cont] = 1;
                val = val/2;
            }
        }
        for (cont = 0; cont <= 4; cont++) {
            printf("%d", bin[cont]);
        }
    }
    else {
        printf("numero invalido");
    }
    printf("\n");
    return 0;
}