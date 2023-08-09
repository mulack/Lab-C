#include <stdio.h>
#include <stdlib.h>

//MODELO DE EXEMPLO

int main() {

	//Variáveis que podem ser usadas
    int x;
    int y;
    int z;
    int k;
    int w;
    int j;
    int i;

	//#########################

    y = 0;
    x = 0;
    printf("Digite os numeros entre 0 e 31\n");
    printf("Digite -1 para encerrar\n\n");
    while(x != -1) {
        //printf("> ");
        scanf("%d",&x);
        if(x >= 0 && x <= 31) {
            y = y | (1 << x);
        }
    }
    printf("______________________________________________\n");
    for(x = 0; x < 32; x++) {
        if(1 & (y >> x)) {
            printf("| %d ",x);
            //printf("| %d |\n",x);
            //printf("%d \n",x);
        }
    }
    
    //#########################
    
    return 0;
}
