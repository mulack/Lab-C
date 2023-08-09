#include <stdio.h>
#include <stdlib.h>
#include "../lib/ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara){
    VETORORD* vetorord = malloc(sizeof(VETORORD));
    vetorord->comparador = compara;
    vetorord->N = n;
    vetorord->P = 0;
    vetorord->elems = malloc(n * sizeof(void *));
    for(int i = 0;i<n;i++){
        vetorord->elems[i] = NULL;
    }
    return vetorord;
}

void VETORD_add(VETORORD* vetor, void* newelem){
    if (vetor->P < vetor->N) {
        if (vetor->P == 0) {
            vetor->elems[0] = newelem;
        }
        else if (
                vetor->comparador(newelem, vetor->elems[vetor->P-1]) == -1 ||
                vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 0
        ) {
            vetor->elems[vetor->P] = newelem;
        }else {
            for (int i = vetor->P-1; i > -1; i--) {
                if (vetor->comparador(newelem, vetor->elems[i]) == 1) {
                    vetor->elems[i+1] = vetor->elems[i];
                    vetor->elems[i] = newelem;
                }
                else break;
            }
        }
        vetor->P++;
    }
}

void* VETORD_remove(VETORORD* vetor){
    void* aux = vetor->elems[0];
    for(int i = 0;i<vetor->P;i++){
        vetor->elems[i] = vetor->elems[i+1]; 
    }
    vetor->P--;
    return aux;
}