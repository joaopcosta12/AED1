#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* esquerda;
    struct Nodo* direita;
} Nodo;

Nodo* criarNodo(int valor) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->valor = valor;
    novoNodo->esquerda = NULL;
    novoNodo->direita = NULL;
    return novoNodo;
}

Nodo* inserir(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return criarNodo(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void percursoPorNivel(Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }

    Nodo* fila[501];
    int inicio = 0;
    int fim = 0;

    fila[fim++] = raiz;

    int primeiroElemento = 1;

    while (inicio < fim) {
        Nodo* atual = fila[inicio++];

        if (primeiroElemento) {
            printf("%d", atual->valor);
            primeiroElemento = 0;
        } else {
            printf(" %d", atual->valor);
        }

        if (atual->esquerda != NULL) {
            fila[fim++] = atual->esquerda;
        }
        if (atual->direita != NULL) {
            fila[fim++] = atual->direita;
        }
    }
}

void liberarArvore(Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);

        Nodo* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);
        percursoPorNivel(raiz);        
        printf("\n");
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
