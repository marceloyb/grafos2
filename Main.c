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
      printf ("<1> Busca em profundidade\n<2> Busca em largura\n\
<3> Componentes fortemente conectados\n<4> Caminho minimo\n<0> Sair\n");
      scanf ("%d", &opcao);

      switch (opcao)
	{
	case 1:
	  	 dfs (&G, *tempo);
	  break;

	case 2:
			 printf ("Insira o vértice desejado para a raiz\n");
			 scanf ("%d", &raiz);
	  	 bfs (&G, raiz);
	  break;

	case 3:
	  //	  scc (&G);
	  break;

	case 4:
	  //	  caminho_minimo (&G);
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
