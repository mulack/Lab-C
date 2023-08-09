#include <stdio.h>
#include <stdlib.h>


int main(){
   
     unsigned int vet[200];
     int valor;
     int cont2;
     int cont1;
     int aux;
     
     aux=0;
     while(aux<200){//preenchendo o vetor com 0
         vet[aux] = 0;
         aux++;
     }
     valor = 0;
     aux = 0;
     printf("Informe os valores entre 0 e 5000: \n");//coletando os valores para serem imprimidos
     while(valor != -1){
       scanf("%d", &valor);
       cont1 = valor / 32;
       if((valor!=-1)&&(valor>=0 && valor<= 5000)){
           vet[cont1] = vet[cont1] | (1 << (valor-(32*cont1)));//adicionando no vetor na pocisão certa, em ordem crescente
           if(valor>aux){
           aux = valor;
        }
       }
       
     }
     valor = 0;
     cont2 = 0;
     printf("Números Digitados: \n");
     while(valor<=aux){
       if((vet[cont2] >> (valor-(32*cont2))) & 1){//imprime os valores que o usuario passou em ordem crescente
         printf("%d\n", valor);
       }
       valor++;
       cont2 = valor / 32;
     }
   
  return 0;  
}