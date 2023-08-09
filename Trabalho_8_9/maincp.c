#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE* f1 = fopen(argv[1], "r"); 
	FILE* f2 = fopen(argv[2], "w");

    int tam_pessoas;
    fscanf(f1,"%d", &tam_pessoas);
    fscanf(f1,"%d", &tam_pessoas);
    
    int qtd_rel;
    fscanf(f1,"%d", &qtd_rel);
    int mat_tam = ((tam_pessoas * tam_pessoas) / 32) + 1;
    int * matriz = calloc(mat_tam, sizeof(int));
    //int matriz[tam_pessoas][tam_pessoas];
    if(matriz == NULL){
        printf("Erro ao alocar memoria\n");
        exit (EXIT_FAILURE);
    }

    int u1,u2;
    int lugar1, lugar2;
    for(int i = 0;i<qtd_rel;i++){
        fscanf(f1,"%d", &u1);
        fscanf(f1,"%d", &u2);
        //printf("%d %d\n", u1, u2);
        lugar1 = (u1-1) * tam_pessoas + u2-1;
        lugar2 = (u2-1) * tam_pessoas + u1-1;

        matriz[lugar1/32] = matriz[lugar1/32] | (1 << lugar1%32);
        matriz[lugar2/32] = matriz[lugar2/32] | (1 << lugar2%32);
    }

    int l;
    int pos;
    // for(int i = 0;i<tam_pessoas;i++){
    //     for(int x = 0;x<tam_pessoas;x++){
    //         pos = (i * tam_pessoas + x)/32;
    //         l = matriz[pos];
    //         if(((matriz[pos] >> ((i * tam_pessoas + x)%32)) & 1)){
    //             printf("%d ", 1);
    //         }else{
    //             printf("%d ", 0);
    //         }
    //     }
    //     printf("\n");
    // }

    int vet_tam = (tam_pessoas/32 + 1);
    int * vetatual = malloc(vet_tam * sizeof(int));
    int * vetmaior = malloc(vet_tam * sizeof(int));
    
    for(int x = 0;x < vet_tam;x++){
        vetatual[x] = 0;
        vetmaior[x] = 0;
    }
    
    int countvetat = 0;
    int countvetma = 0;
    int am = 0;
    int pos1, pos2;
    for (int i = 0; i < tam_pessoas; i++){
        countvetma = 0;
        countvetat = 0;
        vetatual[i/32] = vetatual[i/32] | (1 << (i%32));
        for(int x = 0; x < tam_pessoas;x++){
            pos1 = (i * tam_pessoas + x)/32;

            if((matriz[pos1] >> ((i * tam_pessoas + x)%32)) & 1){
                
                for (int y = 0; y < tam_pessoas; y++){
                    pos2 = (x * tam_pessoas + y)/32;
                    if((vetatual[y/32] >> (y%32)) & 1){
                        if((matriz[pos2] >> ((x * tam_pessoas + y)%32)) & 1){
                            am = 1;
                        }else{
                            am = 0;
                            break;
                        }
                    }
                }
                vetatual[x/32] = vetatual[x/32] | (am << (x%32));
            }
        }
        for(int z = 0;z < tam_pessoas;z++){
            if((vetmaior[z/32] >> (z%32)) & 1){
                countvetma++;
            }
        }
        for(int z = 0;z < tam_pessoas;z++){
            if((vetatual[z/32] >> (z%32)) & 1){
                countvetat++;
            } 
        }
        if(countvetat > countvetma){
            for (int z = 0; z < vet_tam; z++){
                vetmaior[z] = vetatual[z];
            }
        }
        for(int x = 0;x < vet_tam;x++){
            vetatual[x] = 0;
        }
    }
    
    fprintf(f2, "%d\n", countvetma);
    for (int i = 0; i < tam_pessoas; i++){
        if((vetmaior[i/32] >> (i%32)) & 1){
            printf("%d ", i+1);
            fprintf(f2, "%d\n", i+1);
        } 
    }
    
	return 0;
}