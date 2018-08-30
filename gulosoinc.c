// RENAN BABINSKI
//*******ALTERAR LINHA E COLUNA CONFORME TAMANHO DA MATRIZ*******
#include <stdio.h>
#include <stdlib.h>
#define linha 5
#define coluna 8

int verificaVetor(int*vet,int tamanho,int chave){
	for(int i=0;i<=tamanho;i++){
		if(*vet == chave)
			return 1;
		vet++;
	}
	return 0;
}

int main(){

	//Matriz de incidencia 7x7 questão A:
	int vet [linha][coluna] = {{20,0,0,0,0,0,30,-3},{0,0,0,0,50,-10,-30,0},{0,-10,0,5,0,10,0,3},
	{0,0,-30,-5,50,0,0,0},{-20,10,30,0,0,0,0,0}};

	//Matriz de incidencia 7x9 questão B:
	//int vet [linha][coluna] = {{2,0,0,0,6,0,0,12,0},{-2,1,0,5,0,0,0,0,0},{0,-1,40,0,0,0,0,0,0,},
	//{0,0,0,0,-6,4,0,0,0},{0,0,0,0,0,0,0,-12,30},{0,0,0,-5,0,-4,8,0,0},{0,0,-40,0,0,0,-8,-,-30}};

	int caminho[20];

	int i=0,j=0,menor=0,c=0,pont=0;

	caminho[c++] = i+1;
	
	while(1){
		while(j < coluna){
			if(menor == 0 && vet[i][j] > 0){
				menor = vet[i][j];
				pont = j;
			}
			if(menor > vet[i][j] && vet[i][j] > 0){
				menor = vet[i][j];
				pont = j;
			}
			j++;
		}
		for(i=0;i<linha;i++){
			if(vet[i][pont] == menor*-1)
				break;
			if(vet[i][pont] == menor && !verificaVetor(&caminho[0],c,i+1))
				break;
		}
		if(i == 5)
			i--;
		if(verificaVetor(&caminho[0],c,i+1))
			break;
		caminho[c] = i+1;
		j=0;
		c++;
	 	menor=0;





	}




	i = 0;
	printf("\n\nCAMINHO:\n\n");
	while(i < c){
		printf("%d\n",caminho[i]);
		i++;
	}
	return 0;
}

