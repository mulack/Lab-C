#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/TR67.h" //isso deve ser mudado para o nome do arquivo com sua matricula.

int main(int argc, char** argv){
	FILE* fa = fopen(argv[1], "r"); 
	FILE* fb = fopen(argv[2], "r");
	FILE* fc = fopen(argv[3], "w");
	FILE* fd = fopen(argv[4], "w");

	Set* A = readSet(fa);// cria o conjunto A
	Set* B = readSet(fb);// cria o conjunto B
	Set* C = emptySet();// cria o conjunto C como um conjunto vazio
	Set* D = emptySet();// cria o conjunto D como um conjunto vazio

	//printf("%d\n", A->list[0]);


	double time_spent = 0.0;
	clock_t begin = clock();
	//C é a união dos conjuntos A e B
	unionSet(C,A,B);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tempo de execucao da uniao: %f segundos \n", time_spent);

	//printf("%d\n", C->list[0]);

	time_spent = 0.0;
	begin = clock();
	//D é a intersecao dos conjuntos A e B
	intersecSet(D,A,B);
	end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tempo de execucao da intersecao: %f segundos \n", time_spent);
	
	writeSet(fc, C);// escreve o conjunto C no arquivo fc
	writeSet(fd, D); // escreve o conjunto D no arquivo fd
	

	fclose(fa);
	fclose(fb);
	fclose(fc);
	fclose(fd);

	return 0;
}

