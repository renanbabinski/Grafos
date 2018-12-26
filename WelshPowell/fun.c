//##RENAN LUIZ BABINSKI##
#include <stdio.h>
#include <stdlib.h>
#define tamanho 11

typedef struct Graus{
	int vert;
	int grau;
	int color;
}grau;

void popula_matriz(int matriz[][tamanho]){
					      			 //0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10
	int aux[tamanho][tamanho] = /*0*/{{0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 },
					  			 /*1*/{1 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
								 /*2*/{0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
								 /*3*/{0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 },             //MATRIZ DE ADJACENCIA
								 /*4*/{0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 },
								 /*5*/{0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 },
							     /*6*/{0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,1 },
								 /*7*/{1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,1 },
								 /*8*/{0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,0 },
								 /*9*/{0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,1 },
								/*10*/{0 ,0 ,0 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,0 }};
					  
	for(int i=0;i<tamanho;i++)
		for(int j=0;j<tamanho;j++)
			matriz[i][j] = aux[i][j];
}

void popula_graus(grau* vet_graus,int matriz[][tamanho]){    //popula o vetor de vertices com seus valores iniciais
	for(int i=0;i<tamanho;i++){
		vet_graus[i].grau = 0;
		vet_graus[i].vert = i;
		vet_graus[i].color = -1;
		for(int j=0;j<tamanho;j++){
			if(matriz[i][j] != 0)
				vet_graus[i].grau++;
		}
	}

}

void bubbleSort(grau* vet, int n){     //método bubblle sort de Estruturas de dados I para organizar o vetor de graus
	int i, trocou;
	grau aux;
	do{
		trocou = 0;
		for(i=1;i<n;i++){
			if(vet[i-1].grau > vet[i].grau){
				aux.grau = vet[i-1].grau;
				aux.vert = vet[i-1].vert;
				aux.color = vet[i-1].color;

				vet[i-1].grau = vet[i].grau;
				vet[i-1].vert = vet[i].vert;
				vet[i-1].color = vet[i].color;

				vet[i].grau = aux.grau;
				vet[i].vert = aux.vert;
				vet[i].color = aux.color;

				trocou = 1;
			}
		}
	}while(trocou == 1);
}

void popula_abertos(grau vet_graus[],int* abertos){   //popula o vetor de vertices não coloridos
	for(int i=0;i<tamanho;i++)
		abertos[i]=vet_graus[i].vert;
}

int abertos_vazio(int* abertos){       //verifica se o vetor de vertices abertos esta vazio
	for(int i=0;i<tamanho;i++)
		if(abertos[i] >= 0)
			return 0;
	return 1;
}

int verifica_abertos(int* abertos,int n){   //verifica se um vertice especifico esta no vetor de abertos
	for(int i=0;i<tamanho;i++)
		if(abertos[i] == n)
			return 1;
	return 0;
}

void remove_abertos(int* abertos,int n){    //remove um vertice especifico do vetor de abertos
	for(int i=0;i<tamanho;i++)
		if(abertos[i]==n)
			abertos[i]=-1;
}
	
