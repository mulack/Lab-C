#include <stdio.h>
#include <stdlib.h>
#include "../lib/heap.h"

HEAP* HEAP_create(int n, COMP* compara){
    HEAP* heap = malloc(sizeof(HEAP));
    heap->comparador = compara;
    heap->N = n;
    heap->P = 0;
    heap->elems = malloc(n * sizeof(void *));
    for(int i = 0;i<n;i++){
        heap->elems[i] = NULL;
    }
    return heap;
}

void HEAP_add(HEAP* vetor, void* newelem){
    if(vetor->P < vetor->N){
        if(vetor->P == 0){
            vetor->elems[0] = newelem;
            vetor->P++;
        }
        else{
            vetor->elems[vetor->P] = newelem;
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

void* HEAP_remove(HEAP* vetor){
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