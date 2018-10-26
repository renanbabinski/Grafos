#include <stdio.h>
#include <stdlib.h>
#define tamanho 8

typedef struct Vertice{
	char vert;
	int dist;
	char vant;
}vertice;

void popula_matriz(int matriz[][tamanho]){
					      			 //0 ,1 ,2 ,3 ,4 ,5 ,6 ,7
	int aux[tamanho][tamanho] = /*0*/{{0 ,2 ,0 ,6 ,5 ,0 ,0 ,0},
					  			 /*1*/{2 ,0 ,7 ,7 ,0 ,0 ,0 ,0},
								 /*2*/{0 ,7 ,0 ,0 ,6 ,2 ,0 ,0},
								 /*3*/{6 ,7 ,0 ,0 ,0 ,0 ,0 ,0},             //MATRIZ DE ADJACENCIA
								 /*4*/{5 ,0 ,6 ,0 ,0 ,0 ,4 ,5},
								 /*5*/{0 ,0 ,2 ,0 ,0 ,0 ,4 ,6},
							     /*6*/{0 ,0 ,0 ,0 ,4 ,4 ,0 ,1},
								 /*7*/{0 ,0 ,0 ,0 ,5 ,6 ,1 ,0}};
					  

	for(int i=0;i<tamanho;i++)
		for(int j=0;j<tamanho;j++)
			matriz[i][j] = aux[i][j];
}

void popula_vetor(vertice *vetor){   //popula vetor de backtracking com valores  ''default''
	for(int i=0;i<tamanho;i++){
		vetor->vert = 'a' + i;
		vetor->dist = 100;
		vetor->vant = '\\';
		vetor++;
	}
}

int convert(char letra){     //converte letra em um inteiro respectivo a sua posição no alfabeto
	return letra - 'a';
}

char convertint(int nvertice){
	return 'a' + nvertice;
}

void inicia_abertos(char* fila,vertice *vetor){     //coloca todos os vertices no vetor de vertices abertos
	for(int i=0;i<tamanho;i++){
		fila[i] = vetor->vert;
		vetor++;
	}
}

void remove_abertos(char* abertos, char letra){    //remove um vertice desejado do vetor abertos
	for(int i=0;i<tamanho;i++)
		if(abertos[i] == letra)
			abertos[i] = ' ';
}

int abertos_vazio(char* abertos){         //verifica se o vetor de abertos esta vazio
	for(int i=0;i<tamanho;i++){
		if(abertos[i] != ' ')
			return 0;
	}
	return 1;
}

int verifica_abertos(char* abertos,char letra){      //verifica se um vertice especifico esta no vetor de abertos
	for(int i=0;i<tamanho;i++){
		if(abertos[i] == letra)
			return 1;
	}
	return 0;
}

char menor_aberto(vertice *vetor,char* abertos){       //pega o menor vertice do vetor de backtracking que esteja contido nos abertos
	int menor=100000;
	char letra;
	for(int i=0;i<tamanho;i++){
		if(vetor[i].dist < menor && verifica_abertos(abertos,vetor[i].vert)){
			menor = vetor[i].dist;
			letra = vetor[i].vert;
		}
	}
	return letra;
}