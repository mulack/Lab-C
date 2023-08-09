#include <stdio.h>
#include <stdlib.h>

#ifndef ORDVETOR_H
#define ORDVETOR_H

typedef int COMP(void* x, void* y);

//Vetor ordenado estatico. Os elementos do vetor estao colocadoo no vetor
//de acordo com a ordem indicada por comparador.

typedef struct vet{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}VET;

VET* VETORD_create(int n, COMP* compara);

void VETORD_add(VET* vetor, void* novo_elems);

void* VETORD_remove(VET* vetor);

#endif
