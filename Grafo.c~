#include "Grafo.h"

#include <stdlib.h>

void inicializar_grafo (GRAFO *G, int nV, int nA, int dir)
{
  int i, j;

  G->nV = nV;
  G->nA = nA;
  G->dir = dir;
    
  G->cor = (enum Cor *) malloc (nV * sizeof (enum Cor));
  for (j = 0; j < nV; ++j)
    G->cor[j] = 0;
  
  G->pai = (int *) malloc (nV * sizeof (int));
  for (j = 0; j < nV; ++j)
    G->pai[j] = 0;
  
  G->t_inicio = (int *) malloc (nV * sizeof (int));
  for (j = 0; j < nV; ++j)
    G->t_inicio[j] = 0;
  
  G->t_fim = (int *) malloc (nV * sizeof (int));
  for (j = 0; j < nV; ++j)
    G->t_fim[j] = 0;

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

  if (G->dir)
    G->adj[destino][origem] = peso;
}
