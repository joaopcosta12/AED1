#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[10005];
int pai[1005];

int cmp(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int find(int i) {
    if (pai[i] == i) return i;
    return pai[i] = find(pai[i]);
}

void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        pai[root_i] = root_j;
    }
}

int main() {
    int R, C, i;
    scanf("%d %d", &R, &C);

    for (i = 0; i < C; i++) {
        scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
    }

    for (i = 1; i <= R; i++) pai[i] = i;

    qsort(arestas, C, sizeof(Aresta), cmp);

    int custo = 0;
    for (i = 0; i < C; i++) {
        if (find(arestas[i].u) != find(arestas[i].v)) {
            unite(arestas[i].u, arestas[i].v);
            custo += arestas[i].peso;
        }
    }

    printf("%d\n", custo);
    return 0;
}
