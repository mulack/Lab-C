#include <stdio.h>
#include <stdlib.h>
#include "../lib/ordvetor.h"

VET* VETORD_create(int n, COMP* compara){//Cria um vetor ordernado vazio de tamanho n e com funcao de comparacao compara;
    VET* novo = malloc(sizeof(VET));
    novo->comparador = compara;
    novo->N = n;
    novo->P = 0;
    novo->elems = malloc(n * sizeof(void *));
    for(int i = 0;i<n;i++){
        novo->elems[i] = NULL;
    }
    return novo;
}

void VETORD_add(VET* vetor, void* novo_elems){
    /*Adiciona o elemento novo_elems ao vetor ordenado, na posicao correta se for possível
ainda incluir o elemento (se existe espaco no vetor). O vetor deve estar ordenado em
ordem crescente, ou seja: x[i] é menor que ou equivalente a x[j] para todo i < j;*/
    if (vetor->P < vetor->N) {
        if (vetor->P == 0) {
            vetor->elems[0] = novo_elems;
        }
        else if (
                vetor->comparador(novo_elems, vetor->elems[vetor->P-1]) == -1 ||
                vetor->comparador(novo_elems, vetor->elems[vetor->P-1]) == 0
        ) {
            vetor->elems[vetor->P] = novo_elems;
        }else {
            for (int i = vetor->P-1; i > -1; i--) {
                if (vetor->comparador(novo_elems, vetor->elems[i]) == 1) {
                    vetor->elems[i+1] = vetor->elems[i];
                    vetor->elems[i] = novo_elems;
                }
                else break;
            }
        }
        vetor->P++;
    }
}

void* VETORD_remove(VET* vetor){//Remove o menor elemento do vetor, de acordo com a funcao compara.
    void* aux = vetor->elems[0];
    for(int i = 0;i<vetor->P;i++){
        vetor->elems[i] = vetor->elems[i+1]; 
    }
    vetor->P--;
    return aux;
}
