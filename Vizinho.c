#include "Grafo.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void tsp_nn (GRAFO *G)
{
  int i, j, k, custo;
  
  /* Vetor que contem os vertices na ordem em que sao visitados */
  int *caminho;
  /* +1 se deve ao vertice inicial repetido ao fechar o ciclo */
  caminho = malloc ((G->nV + 1) * sizeof (int)); 

  /* Considera o vertice 0 como inicial */
  caminho[0] = 0;

  int v = 0;

  /* Como a cada iteracao eh adicionado um vertice ao vetor, apos nV iteracoes
     teremos todos os vertices no vetor */
  for (i = 1; i < G->nV; ++i)
    {
      /* O mais proximo que se pode chegar do infinito */
      int menor = INT_MAX;
      int u;
      
      /* Encontra o vertice mais proximo a v que nao esta em caminho */
      for (j = 0; j < G->nV; ++j)
	{
	  int pode_inserir = 1;
	  
	  /* Verifica se j nao esta em caminho */
	  for (k = 0; k < i; ++k)
	    {
	      /* Se esta no caminho nao pode inserir ou eh o proprio vertice*/
	      if (caminho[k] == j || v == j)
		pode_inserir = 0;
	    }
	  
	  if (pode_inserir && G->adj[v][j] && G->adj[v][j] < menor)
	    {
	      menor = G->adj[v][j];
	      u = j; /* Vertice que sera inserido */
	    }
	}
      
      /* Insere o vetor encontrado no caminho */
      caminho[i] = u;
      v = u;
    }
  /* Insere novamente o vertice 0 para encerrar o ciclo */
  caminho[G->nV];

  /* Pega o custo total do caminho */
  custo = 0;
  for (i = 0; i < G->nV; ++i)
    custo += G->adj[caminho[i]][caminho[i+1]];

  /* Escreve o resultado */
  for (i = 0; i < G->nV+1; ++i)
    {
      printf ("%d ", caminho[i]);
      if (i != G->nV)
	printf ("-> ");
    }
  puts ("");

  printf ("Custo total = %d\n\n", custo);

  /* Limpa o vetor alocado para armazenar o caminho para evitar vazamento
     de memoria */
  free (caminho);
}
      
