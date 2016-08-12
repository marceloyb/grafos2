#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"

void menu (int *tempo);
void ler_grafo (char * nome);

GRAFO G;

int main (int argc, char **argv)
{
  int i, j, tempo = 0;
  
  if (argc < 2)
    {
      printf ("Uso: %s <nome do arquivo de entrada>\n", argv[0]);
      exit (1);
    }
  ler_grafo (argv[1]);

  menu (&tempo);
}

void menu (int *tempo)
{
  int opcao;

  while (1)
    {
			int raiz;
      printf ("<1> Arvore geradora mínima\n<2> Vizinho mais proximo\n<0> Sair\n");
      scanf ("%d", &opcao);

      switch (opcao)
	{
	case 1:
			printf ("Insira o vértice desejado para a raiz\n");
			scanf ("%d", &raiz);
	  	prim (&G, raiz); 
	  break;

	case 2:
			// Vizinho mais proximo
	  break;

	case 0:
	  exit (0);

	default:
	  printf ("Opcao invalida\n");
	}
    }
}

void ler_grafo (char *nome)
{
  int nV, nA, dir;
  char str[50];
  char lixo;
  FILE *fp;

  fp = fopen (nome, "r");
  fscanf (fp, "%d", &nV);
  fscanf (fp, "%d", &nA);
  fscanf (fp, "%d", &dir);

  inicializar_grafo (&G, nV, nA, dir);

  fscanf (fp, "%*c", &lixo);

  while (!feof (fp))
    {
      int origem, destino, peso = 1;

      fgets (str, 50, fp);
      sscanf (str, "%d %d %d", &origem, &destino, &peso);
      inserir_vertice (&G, origem, destino, peso);
    }

}
