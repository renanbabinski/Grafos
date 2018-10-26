#include <stdio.h>
#include <stdlib.h>
#define tamanho 8

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
char convertint(int nvertice);

int main(){

	int matriz[tamanho][tamanho];
	popula_matriz(matriz);       //popula a matriz com a respectiva matriz de adjacencia

	vertice vetor[tamanho];
	popula_vetor(vetor);        //popula o vetor de backtracking com valores padrão

	char abertos[tamanho];
	inicia_abertos(abertos,vetor);     //joga todos os vertices para o vetor de abertos

	int linha,n;
	char atual; 

	system("clear");
	do{
		printf("\nDigite o numero do vertice onde deseja começar:\n");
		scanf("%d",&n);
		getchar();
		if(n > tamanho || n < 0)
			printf("\nVertice invalido!\n");
	}while(n > tamanho || n < 0);

	atual = convertint(n);

	vetor[convert(atual)].dist = 0;     //define a distancia do vertice inicial como 0

	while(!abertos_vazio(abertos)){       //enquanto houver vertices abertos
		atual = menor_aberto(vetor,abertos);        //vertice atual será sempre o menor 
		linha = convert(abertos[convert(atual)]);
		for(int i=0;i<tamanho;i++){
			if(verifica_abertos(abertos,vetor[i].vert) && matriz[linha][i] != 0){     //se o vertice esta aberto e for diferente de 0, continue
				if(matriz[linha][i] < vetor[i].dist){             //se a a distancia do proximo vertice é menor que o vertice atual, continue e substitua
					vetor[i].dist = matriz[linha][i];             
					vetor[i].vant = vetor[linha].vert;
				}
			}
		}
		remove_abertos(abertos,atual);        //remove o vertice atual dos abertos
		system("clear");

		printf("\n");

		for(int i=0;i<tamanho;i++){ 
			if(vetor[i].vant != '\\'){
				printf("%d ,%d ,%d \n",convert(vetor[i].vert),vetor[i].dist,convert(vetor[i].vant));
			}else{
				printf("%d ,%d ,%c \n",convert(vetor[i].vert),vetor[i].dist,vetor[i].vant);
			}
		}

		printf("\nABERTOS :");

		for(int i=0;i<tamanho;i++){
			printf("%c ",abertos[i]);
		}

		getchar();
	}

	printf("\nARESTAS DA ÁRVORE GERADORA MINIMA:");

	for(int i=0;i<tamanho;i++){   
		if(vetor[i].vant != '\\')
			printf("\n%d -> %d",convert(vetor[i].vert),convert(vetor[i].vant));
	}

	printf("\n");

	n = 0;
	for(int i=0;i<tamanho;i++){
		n = n + vetor[i].dist;
	}
	printf("CUSTO TOTAL: %d\n",n);

	return 0;
}