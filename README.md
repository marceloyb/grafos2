# grafos2

Marcelo Yuri Benesciutti RA: 90565
Pedro Garozi RA: 90552

A linguagem usada foi C.

Para compilar o programa digite no terminal:
gcc filaPrioridadeDin.c Grafo.c Main.c prim.c Vizinho.c

A nao ser que seja especificada a opcao de compilacao -o <nome da saida>,
o nome do programa sera a.out. Para executa-lo basta digitar, estando no
diretorio no qual se encontra: ./a.out <nome do arquivo de entrada>

O algoritmo do vizinho mais proximo foi implementado sem problemas, ja o da
arvore minima (o escolhido foi Prim) nao esta funcionando corretamente,
causando um erro fatal que causa o termino do programa. O problema do Prim
se deve a dificuldade de lidar com a fila de prioridade que implementamos.