#include <stdio.h>
#include <stdlib.h>
#define tamanho 7

typedef struct Vertice{
	char vert;
	int dist;
	char vant;
}vertice;

void popula_matriz(int matriz[][tamanho]);
void popula_vetor(vertice *vetor);
void inicia_abertos(char* abertos,vertice* vetor);
void remove_abertos(char* abertos, char letra);
int convert (char letra);
int abertos_vazio(char* abertos);
int verifica_abertos(char* abertos,char letra);
char menor_aberto(vertice *vetor,char* abertos);

int main(){

	int matriz[tamanho][tamanho];
	popula_matriz(matriz);       //popula a matriz com a respectiva matriz de adjacencia

	vertice vetor[tamanho];
	popula_vetor(vetor);        //popula o vetor de backtracking com valores padrão

	char abertos[tamanho];
	inicia_abertos(abertos,vetor);     //joga todos os vertices para o vetor de abertos

	int linha,aux;
	char atual = 'a';        //define 'a' como vertice inicial

	vetor[convert(atual)].dist = 0;     //define a distancia do vertice inicial como 0

	while(!abertos_vazio(abertos)){       //enquanto houver vertices abertos
		atual = menor_aberto(vetor,abertos);        //vertice atual será sempre o menor 
		linha = convert(abertos[convert(atual)]);
		for(int i=0;i<tamanho;i++){
			if(verifica_abertos(abertos,vetor[i].vert) && matriz[linha][i] != 0){     //se o vertice esta aberto e for diferente de 0, continue
				if(matriz[linha][i] + vetor[linha].dist < vetor[i].dist){             //se a soma do proximo vertice com o atual for menor do que o valor ja registrado, continue
					vetor[i].dist = vetor[linha].dist + matriz[linha][i];             
					vetor[i].vant = vetor[linha].vert;
				}
			}
		}
		remove_abertos(abertos,atual);        //remove o vertice atual dos abertos
		system("clear");

		printf("\n");

		for(int i=0;i<tamanho;i++){ 
		printf("%c ,%d ,%c \n",vetor[i].vert,vetor[i].dist,vetor[i].vant);
		}

		printf("\nABERTOS :");

		for(int i=0;i<tamanho;i++){
			printf("%c ",abertos[i]);
		}

		getchar();
	}

	for(int i=0;i<tamanho;i++){       
		printf("\nSAINDO DE %c ,INDO PARA 'A': ",vetor[i].vert);     //printa a matriz de backtracking
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