#include <stdlib.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1

typedef struct estrutura {
    int info;
    int prioridade;
    struct estrutura *prox;
} NO;

typedef struct {
    NO *inicio, *fim;
} FILA_P;

void inicializar (FILA_P *fi) {
    fi -> inicio = NULL;
    fi -> fim = NULL;
}

void mostrar(FILA_P fi) {
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

void inserir (int novaInfo, int novaPriori, FILA_P *fi) {
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

int alterarPrioridade(FILA_P *fi, int info, int priori) {
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

NO *buscaMaiorPrioridade(FILA_P fi, NO* *ant) {
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

int remover(FILA_P *fi) {
    if(!fi->inicio)    return FALSE;
    NO *ant, *alvo;

    alvo = buscaMaiorPrioridade(fi, &ant);
    if(!alvo)   return NULL;
    ant->prox = alvo->prox;


}
//
//NO *primeiroElem(FILA_P fi) {
//    if (!fi.inicio) {
//        printf("\nFila Vazia.");
//        return FALSE;
//    }
//    printf("\nPrimeiro: %i/%i", fi.inicio -> chave, fi.inicio -> info);
//    return fi.inicio;
//}
//
//NO *ultimoElem(FILA_P fi) {
//    if (!fi.fim) {
//        printf("\nFila Vazia.");
//        return FALSE;
//    }
//    printf("\nUltimo: %i/%i", fi.fim -> chave, fi.fim -> info);
//    return fi.fim;
//}
//
//int tamanho(FILA_P fi) {
//    int tam = 0;
//    while (fi.inicio) {
//        tam += 1;
//        fi.inicio = fi.inicio -> prox;
//    }
//    printf("\nTamanho = %i", tam);
//    return tam;
//}
//
//int desenfilar (FILA_P *fi) {
//   NO * elem;
//   elem = fi -> inicio;
//    if (!elem) {
//        printf("\nFila vazia");
//        return FALSE;
//    }
//    if (fi -> inicio == fi -> fim) {
//        fi -> fim = NULL;
//    }
//    fi -> inicio = elem -> prox;
//    elem -> prox = NULL;
//    printf("\nDesenfilado: %i-%i", elem->chave, elem ->info);
//    free(elem);
//    return TRUE;
//}
//
//void esvaziar(FILA_P *fi) {
////    while(fi -> inicio) {
////        desenfilar(fi);
////    }
//    NO *atual;
//    NO *prox;
//    atual = fi -> inicio;
//    while (atual) {
//        prox = atual -> prox;
//        atual -> prox = NULL;
//        printf("\nExcluido: %i/%i", atual -> chave, atual -> info);
//        free(atual);
//        atual = prox;
//    }
//    fi -> inicio = NULL;
//    fi -> fim= NULL;
//    printf("\nFila Vazia");
//}
//
//void inverte(FILA_P *fi) {
//    NO *p1, *p2;
//    int i, j, k, n, aux;
//    p1 = fi -> inicio;
//    p2 = fi -> fim;
//    n = tamanho(*fi);
//    k = n/2;
//
//    for (j = 0; j < k; j++) {
//        aux = p1 -> info;
//        p1-> info = p2 -> info;
//        p2 -> info = aux;
//
//        p1 = p1 -> prox;
//        n--;
//        p2 = fi -> inicio;
//        for (i = 0; i < n-1; i++) {
//            p2 = p2 -> prox;
//        }
//    }
//}
//
//void separaParImpar(FILA_P *par, FILA_P *impar) {
//    int i, n, ch, valor;
//    n = tamanho(*par);
//    for(i = 0; i<n; i++) {
//        ch = par -> inicio -> chave;
//        valor = par -> inicio -> info;
//        if(valor%2) {
//            inserir(ch, valor, impar);
//        } else {
//            inserir(ch, valor, par);
//        }
//        desenfilar(par);
//    }
//}
//
//void removeMaior(FILA_P *fi) {
//    int i, n, ch, maior, chMaior;
//    n = tamanho(*fi);
//    if (!n) return;
//    maior = fi -> inicio -> info;
//    chMaior = fi -> inicio -> chave;
//    NO *p = fi -> inicio;
//    // Precorrer a fila ate encontrar o maior
//    for(i = 0; i < n; i++) {
//        if(p -> info > maior) {
//            maior = p -> info;
//            ch = p -> chave;
//        }
//        p = p -> prox;
//    }
//    // Percorrer novamente a fila
//    p = fi -> inicio;
//    for (i = 0; i < n; i++) {
//        if (p -> info != maior) {
//            inserir(p -> chave,ṕ -> info, fi);
//        }
//        p = p -> prox;
//        desenfilar(fi);
//    }
//}

int main() {
    FILA_P fila, fImpar;
    inicializar (&fila);
    inserir(10, 1, &fila);
    inserir(20, 2, &fila);
    inserir(30, 3, &fila);
    inserir(20, 4, &fila);
    mostrar(fila);
    //alterarPrioridade(&fila, 20, 0);
    //mostrar(fila);
    remover(&fila);
    mostrar(fila);
//    separaParImpar(&fila, &fImpar);
//    mostrar(fila);
//    mostrar(fImpar);
}
