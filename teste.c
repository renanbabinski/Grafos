#include <stdio.h>
#include <stdlib.h>
#define linha 5
#define coluna 5

int verificaVetor(int*vet,int tamanho,int chave){
	for(int i=0;i<=tamanho;i++){
		if(*vet == chave)
			return 1;
		vet++;
	}
	return 0;
}

int main(){

	int vetor[10] = {1,2,3,4,5,6,7,8,9,0};
	printf("%d\n",verificaVetor(vetor,9,1));
	printf("%d\n",verificaVetor(vetor,9,2));
	printf("%d\n",verificaVetor(vetor,9,3));
	printf("%d\n",verificaVetor(vetor,9,4));
	printf("%d\n",verificaVetor(vetor,9,5));
	printf("%d\n",verificaVetor(vetor,9,6));
	printf("%d\n",verificaVetor(vetor,9,7));
	printf("%d\n",verificaVetor(vetor,9,8));
	printf("%d\n",verificaVetor(vetor,9,9));
	printf("%d\n",verificaVetor(vetor,9,0));
	//printf("%d\n",verificaVetor(&vetor[0],9,9));

	/*for(int i=0;i<10;i++){
		printf("%d\n",vetor[i]);
	}*/


	return 0;
}

