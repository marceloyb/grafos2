#include "Grafo.h"

#include <stdlib.h>

void inicializar_grafo (GRAFO *G, int nV, int nA)
{
  int i, j;

  G->nV = nV;
  G->nA = nA;

  G->cor = (enum Cor *) malloc (nV * sizeof (enum Cor));
  for (j = 0; j < nV; ++j)
    G->cor[j] = branco;

  G->pai = (int *) malloc (nV * sizeof (int));
  for (j = 0; j < nV; ++j)
    G->pai[j] = 0;
  
  G->chave = (int *) malloc (nV * sizeof (int));
  for (j = 0; j < nV; ++j)
    G->chave[j] = 0;
  
  G->distancia = (int *) malloc (nV * sizeof (int));
  for (j = 0; j < nV; ++j)
    G->distancia[j] = 0;
  
  G->adj = (int **) malloc (nV * sizeof (int *));
  for (i = 0; i < nV; ++i)
    {
      G->adj[i] = (int *) malloc (nV * sizeof (int));
      for (j = 0; j < nV; ++j)
	G->adj[i][j] = 0;
    }
}

void inserir_vertice (GRAFO *G, int origem, int destino, int peso)
{
  G->adj[origem][destino] = peso;
  G->adj[destino][origem] = peso;
}

void limpar_grafo (GRAFO *G)
{
  int i;

  free (G->pai);
  free (G->chave);
  free (G->distancia);
  for (i = 0; i < G->nV; ++i)
    free (G->adj[i]);
  free (G);
}
