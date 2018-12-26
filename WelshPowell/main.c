//##RENAN LUIZ BABINSKI##
#include <stdio.h>
#include <stdlib.h>
#define tamanho 11

typedef struct Graus{		
	int vert;
	int grau;
	int color;
}grau;

void popula_matriz(int matriz[][tamanho]);
void popula_graus(grau* vet_graus,int matriz[][tamanho]);
void bubbleSort(grau* vet, int n);
void popula_abertos(grau* vet_graus,int* abertos);
int abertos_vazio(int* abertos);
int verifica_abertos(int* abertos,int n);
void remove_abertos(int* abertos,int n);

int main(){

	int matriz[tamanho][tamanho];   //matriz de adjacencia
	popula_matriz(matriz);

	grau vet_grau[tamanho];       //vetor de vertices ordenado por grau decrescente
	popula_graus(vet_grau,matriz);
	bubbleSort(vet_grau,tamanho);

	grau vet_grau_fixo[tamanho];	//vetor de vertices ordenado por numero de vertice
	popula_graus(vet_grau_fixo,matriz);

	int abertos[tamanho];            //vetor de vertices não coloridos
	popula_abertos(vet_grau,abertos);

	int color=0,j;

	printf("\nVetor de vertices organizados por numeração:\n");     

	for(int i=0;i<tamanho;i++){
		printf("\nVertice:%c , Grau:%d , Cor:%d",'a'+vet_grau_fixo[i].vert,vet_grau_fixo[i].grau,vet_grau_fixo[i].color);   //vetor de vertices antes de ser organizado
	}

	printf("\n\nVetor de vertices organizados por grau\n");

	for(int i=0;i<tamanho;i++){
		printf("\nVertice:%c , Grau:%d , Cor:%d",'a'+vet_grau[i].vert,vet_grau[i].grau,vet_grau[i].color);   //vetor de vertices organizado
	}
	getchar();
	system("clear");

	while(!abertos_vazio(abertos)){    //enquanto houver vertices abertos continue
		for(int i=tamanho-1;i>=0;i--){      //percorre o vetor de vertices do maior grau para o menor
			if(verifica_abertos(abertos,vet_grau[i].vert)){      //verifica se o vertice esta no vetor de abertos
				for(j=0;j<tamanho;j++){                          //percore a linha da matriz
					if(matriz[vet_grau[i].vert][j] != 0 && vet_grau_fixo[j].color == color)       //se o valor da matriz for diferente de 1, e, as cores forem iguais
						break;                                                                   //se a condição for atendida ocorreu um conflito de cores
				}
				if(j==tamanho){                                          //se o loop acima rodar até o fim, não houve conflito de cores e o vertice poderá ser pintado na cor atual
					vet_grau[i].color = color;                           //pinta o vertice no vetor organizado
					vet_grau_fixo[vet_grau[i].vert].color = color;       //pinta o vertice no vetor fixo
					remove_abertos(abertos,vet_grau[i].vert);			 //após ser pintado o verice é removido dos abertos
				}
			}
		}
		color++;                                                      //após colorir todos os vertices possiveis, troque de cor
		for(int i=0;i<tamanho;i++){
		printf("\nVertice:%c , Grau:%d , Cor:%d",'a'+vet_grau_fixo[i].vert,vet_grau_fixo[i].grau,vet_grau_fixo[i].color);
		}
		getchar();
	}


return 0;
}