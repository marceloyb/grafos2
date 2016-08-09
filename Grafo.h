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
  int *pai;
  int *t_inicio;
  int *t_fim;
  int **adj;
};

void dfs (GRAFO *G, int tempo);
void bfs (GRAFO *G, int raiz);
void scc (GRAFO *G);
void caminho_minimo (GRAFO *G);

void inicializar_grafo (GRAFO *G, int nV, int nA, int dir);
void inserir_vertice (GRAFO *G, int origem, int destino, int peso);

#endif
