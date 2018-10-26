//##RENAN LUIZ BABINSKI##
#include <stdio.h>
#include <stdlib.h>
#define tamanho 8

typedef struct Arestas{   //Estrutura do vetor de arestas
	int vi;
	int vj;
	int peso;
}aresta;

typedef struct Back_tracking{  //Estrutura do vetor de vertices
	int vertice;
	int p;
}backtracking;

int popula_matriz(int matriz[][tamanho]){
					      			 //0 ,1 ,2 ,3 ,4 ,5 ,6 ,7
	int aux[tamanho][tamanho] = /*0*/{{0 ,3 ,4 ,3 ,0 ,0 ,0 ,0},
					  			 /*1*/{3 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
								 /*2*/{4 ,0 ,0 ,0 ,8 ,8 ,0 ,0},
								 /*3*/{3 ,0 ,0 ,0 ,0 ,8 ,0 ,0},             //MATRIZ DE ADJACENCIA
								 /*4*/{0 ,0 ,8 ,0 ,0 ,0 ,7 ,7},
								 /*5*/{0 ,0 ,8 ,8 ,0 ,0 ,4 ,7},
							     /*6*/{0 ,0 ,0 ,0 ,7 ,4 ,0 ,2},
								 /*7*/{0 ,0 ,0 ,0 ,7 ,7 ,2 ,0}};
					  
	for(int i=0;i<tamanho;i++)
		for(int j=0;j<tamanho;j++)
			matriz[i][j] = aux[i][j];

	int i=0,j=0,cont=0;

	while(i < tamanho){
		if(j < i && matriz[i][j] != 0){    //nesse laço é calculado a quantidade de arestas do grafo
			cont++;
			j++;
		}else if(i == j){
			i++;
			j=0;
		}else{
			j++;
		}
	}
	return cont;      //retorna a quantidade de arestas do grafo
}

void popula_pesos(aresta* pesos, int matriz[][tamanho]){     //aqui é definido o vetor de arestas seus vertices iniciais,finais e pesos
	int i=0,j=7,k=0;
	while(i < tamanho){
		if(j > i && matriz[i][j] != 0){
			pesos[k].vi = i;
			pesos[k].vj = j;
			pesos[k].peso = matriz[i][j];
			k++;
			j--;
		}else if(i == j){
			i++;
			j=7;
		}else{
			j--;
		}
	}
}

void bubbleSort(aresta* vet, int n){     //método bubblle sort de Estruturas de dados I para organizar o vetor de arestas
	int i, trocou;
	aresta aux;
	do{
		trocou = 0;
		for(i=1;i<n;i++){
			if(vet[i-1].peso > vet[i].peso){
				aux.peso = vet[i-1].peso;
				aux.vi = vet[i-1].vi;
				aux.vj = vet[i-1].vj;

				vet[i-1].peso = vet[i].peso;
				vet[i-1].vi = vet[i].vi;
				vet[i-1].vj = vet[i].vj;

				vet[i].peso = aux.peso;
				vet[i].vi = aux.vi;
				vet[i].vj = aux.vj;

				trocou = 1;
			}
		}
	}while(trocou == 1);
}

void popula_backtracking(backtracking* back){      //seta o vetor de vertices aos seus valores padrão
	for(int i=0;i<tamanho;i++){
		back[i].vertice = i;
		back[i].p = -1;
	}
}