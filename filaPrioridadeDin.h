#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

typedef struct estrutura {
    int info;
    int prioridade;
    struct estrutura *prox;
} NO;

typedef struct {
    NO *inicio, *fim;
} FILA_P;

void inicializar (FILA_P *fi);
void mostrar (FILA_P fi);
void inserir (int novaInfo, int novaPriori, FILA_P *fi);
int alterarPrioridade(FILA_P *fi, int info, int priori);
NO *buscaMaiorPrioridade(FILA_P fi, NO* *ant);
int remover(FILA_P *fi);


#endif // not FILA_PRIORIDADE_H
