#ifndef GRAFO_H
#define GRAFO_H

typedef struct GRAFO GRAFO;

enum Cor {branco, cinza, preto};

struct GRAFO
{
  int nV;
  int nA;

  enum Cor *cor;
  int *pai;
  int *chave;
  int *distancia;  
  int **adj;
};

void prim (GRAFO *G, int raiz);
void tsp_nn (GRAFO *G);

void inicializar_grafo (GRAFO *G, int nV, int nA);
void inserir_vertice (GRAFO *G, int origem, int destino, int peso);
void limpar_grafo (GRAFO *G);

#endif
