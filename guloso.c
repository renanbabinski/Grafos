// RENAN BABINSKI
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

	int vet [linha][coluna] = {{0,30,-15,0,20},{-30,0,-10,50,0},{15,10,0,5,-10},{0,50,-5,0,-30},{-20,0,10,30,0}};

	int caminho[20];

	int i=0,j=0,menor=0,c=0;

	caminho[c++] = j+1;
	while(1){
		while(j < coluna){
			if(menor == 0 && vet[i][j] > 0 && !verificaVetor(&caminho[0],c,j+1)){
				menor = vet[i][j];
				caminho[c] = j+1;
			}if(vet[i][j] < menor && vet[i][j] > 0 && !verificaVetor(&caminho[0],c,j+1)){
				menor = vet[i][j];
				caminho[c] = j+1;
			}
			j++;
		}
		if(menor == 0)
			break;
		i = caminho[c] - 1;
		j = 0;
		menor = 0;
		c++;
	}
	i = 0;
	printf("\n\nCAMINHO:\n\n");
	while(i < c){
		printf("%d\n",caminho[i]);
		i++;
	}
	return 0;
}

