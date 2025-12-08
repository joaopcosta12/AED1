#include <stdio.h>
#include <string.h>

#define MAX 2005
 
int grafo[MAX][MAX];
int transposto[MAX][MAX];
int visitados[MAX];
int N, M, contador;

void dfs(int u, int g[][MAX]) {
    visitados[u] = 1;
    contador++;
    for (int v = 1; v <= N; v++) {
        if (g[u][v] && !visitados[v]) {
            dfs(v, g);
        }
    }
}

int main() {
    int V, W, P;

    while (scanf("%d %d", &N, &M) && (N || M)) {
        memset(grafo, 0, sizeof(grafo));
        memset(transposto, 0, sizeof(transposto));

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &V, &W, &P);
            grafo[V][W] = 1;
            transposto[W][V] = 1;
            if (P == 2) {
                grafo[W][V] = 1;
                transposto[V][W] = 1;
            }
        }

        memset(visitados, 0, sizeof(visitados));
        contador = 0;
        dfs(1, grafo);

        if (contador < N) {
            printf("0\n");
        } else {
            memset(visitados, 0, sizeof(visitados));
            contador = 0;
            dfs(1, transposto);

            if (contador < N) printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}
