#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    
    if (valor < raiz->dado) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void prefixa(No* raiz) {
    if (raiz == NULL) return;
    printf(" %d", raiz->dado);
    prefixa(raiz->esq);
    prefixa(raiz->dir);
}

void infixa(No* raiz) {
    if (raiz == NULL) return;
    infixa(raiz->esq);
    printf(" %d", raiz->dado);
    infixa(raiz->dir);
}

void posfixa(No* raiz) {
    if (raiz == NULL) return;
    posfixa(raiz->esq);
    posfixa(raiz->dir);
    printf(" %d", raiz->dado);
}

void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int c, n, valor;
    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        
        No* raiz = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        printf("Pre.:"); prefixa(raiz); printf("\n");
        printf("In..:"); infixa(raiz); printf("\n");
        printf("Post:"); posfixa(raiz); printf("\n\n"); // Corrigido aqui (removeu o ponto)

        liberar(raiz);
    }

    return 0;
}
