// RENAN BABINSKI
// ******** ALTERAR A LINHA E COLUNA CONFORME O TAMANHO DA MATRIZ *********
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

	//Matriz de adjacencia 5x5 da questão A:
	int vet [linha][coluna] = {{0,30,-15,0,20},{-30,0,-10,50,0},{15,10,0,5,-10},{0,50,-5,0,-30},{-20,0,10,30,0}};

	//Matriz de adjacencia 7x7 da questão B:
	//int vet[linha][coluna] = {{0,2,0,6,12,0,0},{-2,0,1,0,0,5,0},{0,-1,0,0,0,0,40},{-6,0,0,0,0,4,0},{-12,0,0,0,0,0,30},
	//{0,-5,0,-4,0,0,8},{0,0,-40,0,-30,-8,0}};

	int caminho[20];

	int i=0,j=0,menor=0,c=0,custo=0;

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
		if(menor != 0){
			custo += menor;
		}else
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
	printf("\n\nCUSTO: %d\n\n",custo);
	return 0;
}

