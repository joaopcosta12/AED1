#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *esq, *dir;
} No;

No* inserir(No* raiz, char v) {
    if (!raiz) {
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = v;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (v < raiz->dado) raiz->esq = inserir(raiz->esq, v);
    else raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

int pesquisar(No* raiz, char v) {
    if (!raiz) return 0;
    if (raiz->dado == v) return 1;
    if (v < raiz->dado) return pesquisar(raiz->esq, v);
    return pesquisar(raiz->dir, v);
}

int primeiro;

void prefixa(No* raiz) {
    if (!raiz) return;
    if (!primeiro) printf(" ");
    printf("%c", raiz->dado);
    primeiro = 0;
    prefixa(raiz->esq);
    prefixa(raiz->dir);
}

void infixa(No* raiz) {
    if (!raiz) return;
    infixa(raiz->esq);
    if (!primeiro) printf(" ");
    printf("%c", raiz->dado);
    primeiro = 0;
    infixa(raiz->dir);
}

void posfixa(No* raiz) {
    if (!raiz) return;
    posfixa(raiz->esq);
    posfixa(raiz->dir);
    if (!primeiro) printf(" ");
    printf("%c", raiz->dado);
    primeiro = 0;
}

int main() {
    char cmd[20], letra;
    No* raiz = NULL;

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        } else if (strcmp(cmd, "P") == 0) {
            scanf(" %c", &letra);
            if (pesquisar(raiz, letra)) printf("%c existe\n", letra);
            else printf("%c nao existe\n", letra);
        } else {
            primeiro = 1;
            if (strcmp(cmd, "PREFIXA") == 0) prefixa(raiz);
            else if (strcmp(cmd, "INFIXA") == 0) infixa(raiz);
            else posfixa(raiz);
            printf("\n");
        }
    }
    return 0;
}
