#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	char vert;
	int dist;
	char vant;
	char color;
}vertice;

void popula_matriz(int matriz[][21]);
void popula_vetor(vertice *vetor);
void inicia_fila(char* fila);
int insere_fila(char* fila,char letra,int pont);
int remove_fila(char* fila, int pont);
int convert (char letra);

int main(){

	int matriz[21][21];
	popula_matriz(matriz); // popula a matriz com a respectiva matriz de adjacencia

	vertice vetor[21];
	popula_vetor(vetor); //inicializa o vetor de backtracking 

	char fila[50];
	inicia_fila(fila); //inicia o vetor fila com ' '

	int pont=0,linha=0,aux;

	pont = insere_fila(fila,'a',pont); //definição do vértice inicial
	vetor[0].dist = 0;  // distancia 0 para o vertice inicial

	while(1){
		if(fila[0] == ' ') //se a fila estiver vazia termina o loop
			break;
		else
			linha = convert(fila[0]);  //converte a letra da fila em um indice para a matriz
		for(int i=0;i<21;i++){
			if(matriz[linha][i] == 1 && vetor[i].color == 'w'){
				vetor[i].dist = vetor[linha].dist + 1;
				vetor[i].vant = vetor[linha].vert;
				vetor[i].color = 'g';
				pont = insere_fila(fila,vetor[i].vert,pont);
			}
		}
		vetor[linha].color = 'b';
		pont = remove_fila(fila,pont);

		system("clear");

		for(int i=0;i<21;i++){ // imprime o vetor de backtracking
			printf("%c ,%d ,%c ,%c \n",vetor[i].vert,vetor[i].dist,vetor[i].vant,vetor[i].color);
		}

		printf("\nFILA : ");

		for(int i=0;i<50;i++){   //imprime a fila
			printf(" %c ",fila[i]);
		}

		getchar();		
	}

	for(int i=0;i<21;i++){       // impressão final do programa com o caminho mais curto para cada vertice até 'A' e seu custo
		printf("\nSAINDO DE %c ,INDO PARA 'A': ",vetor[i].vert);
		printf("---CUSTO: %d ---",vetor[i].dist);
		aux = i;
		while(1){
			printf("%c-> ",vetor[aux].vert);
			if(vetor[aux].vant == '\\')
				break;
			else
				aux = convert(vetor[aux].vant);
		}
	}

	printf("\n");

	return 0;
}