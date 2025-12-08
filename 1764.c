#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int origem;
    int destino;
    int distancia;
} Aresta;

Aresta grafo[50000];
int pai[40000];

int compararArestas(const void *a, const void *b) {
    Aresta* arestaA = (Aresta*)a;
    Aresta* arestaB = (Aresta*)b;
    return arestaA->distancia - arestaB->distancia;
}

int buscar(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = buscar(pai[i]);
}

int unir(int i, int j) {
    int raiz_i = buscar(i);
    int raiz_j = buscar(j);

    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
        return 1; 
    }
    return 0;
}

int main() {
    int M, N;

    while (scanf("%d %d", &M, &N) == 2 && (M != 0 || N != 0)) {
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].distancia);
        }

        for (int i = 0; i < M; i++) {
            pai[i] = i;
        }

        qsort(grafo, N, sizeof(Aresta), compararArestas);

        long long soma_total = 0; 
        
        for (int i = 0; i < N; i++) {
            if (unir(grafo[i].origem, grafo[i].destino)) {
                soma_total += grafo[i].distancia;
            }
        }

        printf("%lld\n", soma_total);
    }

    return 0;
}
