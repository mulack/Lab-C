#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H


typedef int COMP(void* x, void* y);

//Uma Heap estatico. Os elementos do vetor estao colocadoo no vetor
//de acordo com a ordem indicada por comparador.
typedef struct heap{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}HEAP;

HEAP* HEAP_create(int n, COMP* compara);

void HEAP_add(HEAP* heap, void* novo_elems);

void* HEAP_remove(HEAP* heap);


#endif
