#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	char vert;
	int dist;
	char vant;
	char color;
}vertice;

void popula_matriz(int matriz[][21]){
					      //0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0
	int aux[21][21] =/*0*/{{0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
					  /*1*/{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					  /*2*/{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					  /*3*/{0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
					  /*4*/{0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					  /*5*/{0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
					  /*6*/{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
					  /*7*/{0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
					  /*8*/{0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
					  /*9*/{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},           /*MATRIZ DE ADJACENCIA*/
					  /*0*/{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
					  /*1*/{0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
					  /*2*/{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
					  /*3*/{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
					  /*4*/{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
					  /*5*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
					  /*6*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0},
					  /*7*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
					  /*8*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1},
					  /*9*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
					  /*0*/{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0}};

	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			matriz[i][j] = aux[i][j];
}

void popula_vetor(vertice *vetor){  //insere os valores padrao no vetor de backtracking
	for(int i=0;i<21;i++){
		vetor->vert = 'a' + i;
		vetor->dist = 100;
		vetor->vant = '\\';
		vetor->color = 'w';
		vetor++;
	}

}

int convert(char letra){   //converte uma letra em um inteiro respectivamente
	return letra - 'a';

}

void inicia_fila(char* fila){    //inicia a fila com ' '
	for(int i=0;i<50;i++)
		fila[i]= ' ';
}

int insere_fila(char* fila, char letra, int pont){    //inserção na fila
	fila[pont] = letra;
	return ++pont;
}

int remove_fila(char* fila, int pont){      //Remoção da fila
	for(int i=0;i<49;i++){
		if(fila[i] && fila[i+1] != ' ')
			fila[i] = fila[i+1];
		else
			fila[i] = ' ';
	}
	return --pont;
}
