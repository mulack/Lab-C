#include <stdio.h>
#include <stdlib.h>

typedef struct SET{
   int tam;
   int vet_tam;
   int maior;
   float dens;
   int* list;
}Set;

Set* emptySet();

Set* readSet(FILE* file);

void unionSet(Set* uniao, Set* A, Set* B);

void intersecSet(Set* intersec,Set* A,Set* B);

void writeSet(FILE* file, Set* set);

void props(Set* set);