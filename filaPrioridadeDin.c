#include <stdlib.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1


void
inicializar (FILA_P *fi)
{
  fi -> inicio = NULL;
  fi -> fim = NULL;
}

void
mostrar (FILA_P fi)
{
  NO *p = fi.inicio;
  printf("\nInfo/Prioridade");
  printf("\nInicio --> [");
  while (p) {
    printf("%d/%d", p->info, p->prioridade);
    p = p->prox;
    if(p) printf(", ");
  }
  printf("] <-- fim");
}

void
inserir (int novaInfo, int novaPriori, FILA_P *fi)
{
  NO *novo;
  novo = (NO *) malloc (sizeof(NO));
  novo->info = novaInfo;
  novo->prioridade = novaPriori;
  novo->prox = NULL;
  if (!fi->inicio) {
    fi->inicio = novo;
  } else {
    fi->fim->prox = novo;
  }
  fi->fim = novo;

  printf("\nInserido: %i/%i", novaInfo, novaPriori);
}

int
alterarPrioridade (FILA_P *fi, int info, int priori)
{
  NO *p = fi->inicio;
  while(p) {
    if(p->info == info) {
      p->prioridade = priori;
      return TRUE;
    }
    p = p->prox;
  }
  return FALSE;
}

NO *
buscaMaiorPrioridade (FILA_P fi, NO* *ant)
{
  NO *p = fi.inicio;
  NO *pAnt = NULL;
  NO *alvo = p;

  while(p) {
    if(p->prioridade > alvo->prioridade) {
      *ant = pAnt;
      alvo = p;
    }
    pAnt = p;
    p = p->prox;
  }
  return alvo;
}

int
remover (FILA_P *fi)
{
  if(!fi->inicio)
    return FALSE;
  NO *ant, *alvo;

  alvo = buscaMaiorPrioridade(fi, &ant);
  if(!alvo)   return NULL;
  ant->prox = alvo->prox;
}
