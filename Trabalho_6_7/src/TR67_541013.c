#include "TR67_541013.h"

Set* emptySet(){
    Set* set = malloc(sizeof(Set));
    set->tam = 0;
    set->dens = 0;
    set->maior = 0;
    return set;
}

Set* readSet(FILE* file){
    int x;
    int j;
    Set* set = emptySet();
    fscanf(file, "%d\n", &set->tam);
    fscanf(file, "%d\n", &set->maior);
    fscanf(file, "%f\n", &set->dens);
    set->vet_tam = set->maior/32;
    set->list = malloc(set->maior/32 * sizeof(int));
    for (int i = 0; i <= set->maior/32; i++){
        set->list[i] = 0;
    }
    
    for(int i = 0;i<set->tam;i++){
        fscanf(file, "%d\n", &x);
        j = x/32;
        set->list[j] = set->list[j] | (1 << (x-(32*j)));
    }
    return set;
}

void unionSet(Set* uniao, Set* A, Set* B){

    if(A->vet_tam > B->vet_tam){
        uniao->list = malloc(A->vet_tam * sizeof(int));
        uniao->vet_tam = A->vet_tam;
        for (int i = 0; i <= A->vet_tam; i++){
            uniao->list[i] = 0 | A->list[i];
        }
        for (int i = 0; i <= B->vet_tam; i++){
            uniao->list[i] = uniao->list[i] | B->list[i];
        }
        
    }else if(A->vet_tam <= B->vet_tam){
        uniao->list = malloc(B->vet_tam * sizeof(int));
        uniao->vet_tam = B->vet_tam;
        for (int i = 0; i <= B->vet_tam; i++){
            uniao->list[i] = 0 | B->list[i];
        }
        for (int i = 0; i <= A->vet_tam; i++){
            uniao->list[i] = uniao->list[i] | A->list[i];
        }
    }
    
}

void intersecSet(Set* intersec, Set* A, Set* B){
    if(A->vet_tam > B->vet_tam){
        intersec->vet_tam = B->vet_tam;
        intersec->list = malloc(B->vet_tam * sizeof(int));
        for (int i = 0; i <= B->vet_tam; i++){
            intersec->list[i] = A->list[i] & B->list[i];
        }
    }else if(A->vet_tam <= B->vet_tam){
        intersec->vet_tam = A->vet_tam;
        intersec->list = malloc(A->vet_tam * sizeof(int));
        for (int i = 0; i <= A->vet_tam; i++){
            intersec->list[i] = A->list[i] & B->list[i];
        }
    }
}

void writeSet(FILE* file, Set* set){
    int y = 0;
    int w = 0;
    props(set);
    fprintf(file, "%d\n", set->tam);
    fprintf(file, "%d\n", set->maior);
    fprintf(file, "%f\n", set->dens);
    while(w<=set->vet_tam){
        if(set->list[w] != 0){
            if((set->list[w] >> (y-(32*w))) & 1){
            fprintf(file, "%d\n", y);
            }
            y++;
            w = y / 32;
        }else{
            w++;
            y = w*32;
        }
        
    }
}

void props(Set* set){
    int t = 0;
    int y = 0;
    int w = 0;
    while(w<=set->vet_tam){
        if((set->list[w] >> (y-(32*w))) & 1){
            t++;
        }
       y++;
       w = y / 32;
     }
    set->tam = t;

    int m = 0;
    y = 0;
    w = 0;
    while(w<=set->vet_tam){
        if((set->list[w] >> (y-(32*w))) & 1){
            m = y;
        }
       y++;
       w = y / 32;
     }
    set->maior = m;

    set->dens = (float)t/(float)m;
}