#ifndef GRAFO_H
#define GRAFO_H

typedef struct GRAFO GRAFO;

enum Cor {branco, cinza, preto};

struct GRAFO
{
  int nV;
  int nA;
  int dir;
  int *distancia;
  
  enum Cor *cor;
  int *chave;
  int *pai;
  int **adj;
};

void prim (GRAFO *G, int raiz);

void inicializar_grafo (GRAFO *G, int nV, int nA, int dir);
void inserir_vertice (GRAFO *G, int origem, int destino, int peso);

#endif
