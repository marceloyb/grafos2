#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "filaPrioridadeDin.h"

void prim (GRAFO *G, int raiz){
	FILA_P fila;	
	int i, minimo = 0, confere, u=0;
	int *vetor_peso = (int*) malloc (G->nV*sizeof(int));
	// inicializa todos os vertices do grafo
	for (i = 0; i < G->nV; i++){
		G->chave[i] = INT_MAX;
		G->pai[i] = -1;
		G->cor[i] = branco;
		vetor_peso[i] = 0;
	}
	// inicializa raiz
	G->chave[raiz] = 0;
	inicializar(&fila);
	// insere os vertices na fila de prioridade
	for (i = 0; i < G->nV; i++){
		inserir(i, G->chave[i], &fila);
		printf ("tey");
	}
	// faz a busca na fila de prioridade, extrai o minimo e compara com os adj
	// ESSA É A FUNÇÃO COM PROBLEMA PIZZA!
	if (filavazia(fila) == 0){
		printf ("entrou");
		u = buscaMenorPrioridade(fila);
		removermenor(&fila);
	}
	// Imprime caracteristicas dos vertices
	for (i = 0; i < G->nV; i++){
		printf ("\nVertice: %d, Pai: %d, Chave: %d\n", i, G->pai[i], G->chave[i]);
	} 
}
