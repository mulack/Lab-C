#include <stdio.h>
#include <stdlib.h>
#include "../lib/heap.h"

HEAP* HEAP_create(int n, COMP* compara){//Cria um heap vazio de tamanho n e com funcao de comparacao compara
    HEAP* novo = malloc(sizeof(HEAP));
    novo->comparador = compara;
    novo->N = n;
    novo->P = 0;
    novo->elems = malloc(n * sizeof(void *));
    for(int i = 0;i<n;i++){
        novo->elems[i] = NULL;
    }
    return novo;
}

void HEAP_add(HEAP* vetor, void* novo_elems){
/*Adiciona o elemento novo_elems ao Heap, na posicao correta se for possível
ainda incluir o elemento (se existe espaco no vetor elems). Observe que 
a estrutura deve respeitar a regra da heap, ou seja, para todo i temos que 
x[i] é menor que ou equivalente a x[2*i] e a x[2*i+1].*/
    if(vetor->P < vetor->N){
        if(vetor->P == 0){
            vetor->elems[0] = novo_elems;
            vetor->P++;
        }
        else{
            vetor->elems[vetor->P] = novo_elems;
            vetor->P++;
            for(int i=vetor->P-1;i>0;i--){
                if(vetor->comparador(vetor->elems[i], vetor->elems[i/2]) == 1){
                    void* aux = vetor->elems[i];
                    vetor->elems[i] = vetor->elems[i/2];
                    vetor->elems[i/2] = aux;
                }
            }
        }
    }
}

void* HEAP_remove(HEAP* vetor){//Remove o menor elemento do heap, de acordo com a funcao compara
    void* aux = vetor->elems[0];
    for(int i = 0;i<vetor->P;i++){
        vetor->elems[i] = vetor->elems[i+1]; 
    }
    vetor->P--;
    for(int i=vetor->P-1;i>0;i--){
        if(vetor->comparador(vetor->elems[i], vetor->elems[i/2]) == 1){
            void* aux = vetor->elems[i];
            vetor->elems[i] = vetor->elems[i/2];
            vetor->elems[i/2] = aux;
        }
    }
    return aux;
}