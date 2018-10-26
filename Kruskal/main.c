//##RENAN LUIZ BABINSKI##
#include <stdio.h>
#include <stdlib.h>
#define tamanho 8

typedef struct Arestas{   //struct de uma aresta
	int vi;
	int vj;
	int peso;
}aresta;

typedef struct Back_tracking{   //struct vetor de vertices
	int vertice;
	int p;
}backtracking;

int popula_matriz(int matriz[][tamanho]);
void popula_pesos(aresta* pesos, int matriz[][tamanho]);
void bubbleSort(aresta* pesos, int n);
void popula_backtracking(backtracking* back);

int main(){

	int matriz[tamanho][tamanho];
	int qtdarestas = popula_matriz(matriz);

	int vi,vj,custo=0;
	
	aresta pesos[qtdarestas];   //vetor de arestas
	popula_pesos(pesos,matriz);

	backtracking back[tamanho]; // vetor de vertices
	popula_backtracking(back);

	printf("ARESTAS DESORGANIZADAS:\n");

	for(int i=0;i<qtdarestas;i++){
		printf("\n%d , %d , %d",pesos[i].peso,pesos[i].vi,pesos[i].vj);
	}

	bubbleSort(pesos,qtdarestas);

	printf("\n\n");
	printf("ARESTAS ORGANIZADAS:\n");

	for(int i=0;i<qtdarestas;i++){
		printf("\n%d , %d , %d",pesos[i].peso,pesos[i].vi,pesos[i].vj);
	}
	getchar();
	system("clear");

	for(int i=0;i<qtdarestas;i++){
		vi = pesos[i].vi;
		vj = pesos[i].vj;
		while(back[vi].p > -1) //navega até encontrar um p menor ou igual a -1
			vi = back[vi].p;
		while(back[vj].p > -1) //navega até encontrar um p menor ou igual a -1
			vj = back[vj].p;
		if(vi != vj){          //se vi e vj cair em um mesmo vertice, o par pertence a mesma arvore
			custo += pesos[i].peso;
			back[vj].p += back[vi].p;
			back[vi].p = vj;
		}else{					//se forem da mesma arvore defina no vetor de arestas vi e vj como 0, para assim ignora-los
			pesos[i].vi = 0;
			pesos[i].vj = 0;
		}

		printf("PASSO A PASSO...ATUALIZAÇÃO DO VETOR APÓS ARESTA %d",i+1);

		for(int i=0;i<tamanho;i++){
			printf("\n %d , %d",back[i].vertice,back[i].p);   //lista o vetor de vertices a cada passo do vetor de arestas
		}
		getchar();
		system("clear");
	}

	printf("ARESTAS DA ARVORE GERADORA MINIMA: \n");

	for(int i=0;i<qtdarestas;i++){
		if(pesos[i].vi != pesos[i].vj)
			printf("%d -> %d\n",pesos[i].vi,pesos[i].vj);     //lista as arestas que permaneceram no vetor de arestas e que pertencem a arvore geradora minima
	}

	printf("CUSTO TOTAL: %d\n", custo);
	
	return 0;
}