#include <stdlib.h>
#include <malloc.h>
#include "filaPrioridadeDin.h"

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

int filavazia (FILA_P fi){
	if (fi.inicio = NULL)
		return 1;
	else
		return 0;
}

int buscaMenorPrioridade (FILA_P fi){
	int vertice;
	NO *p = fi.inicio;
	NO *alvo = fi.inicio;
	while (p){
		if (p->prioridade < alvo->prioridade){
			alvo = p;
		}
		p = p->prox;
	}	
	vertice = alvo->info;
	printf ("entrou na função de busca");
	return vertice;
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


int buscanafila (FILA_P *fi, int buscado){
	NO *p = fi->inicio;
	NO *pAnt = NULL;
	NO *alvo = p;
	
	while (p){
		if (p->info == buscado){
			//*ant = pAnt;
			//alvo = p;
			return 1;
		}
		//pAnt = p;
		//p = p->prox;
	}
	return 0;
}

int removermenor (FILA_P *fi){
	NO *ant, *alvo;
  if(fi->inicio == NULL)
    return FALSE; 
	else{
		alvo = fi->inicio;
		int infoalvo=0, vertice=0;
  	vertice = buscaMenorPrioridade(*fi);
		infoalvo = alvo->info;
		printf ("%d", buscaMenorPrioridade(*fi));
		if (infoalvo == vertice){			
			printf ("asoidoisajd");
			ant->prox = alvo->prox;
			alvo->prox = NULL;
			printf ("removeu o menor");
		}
		else 
			alvo = alvo->prox;
	}
}
