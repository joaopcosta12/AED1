#include <stdio.h>
#include <stdbool.h>

#define MAXN 505
#define INF 10000000

int adj[MAXN][MAXN];
int dist[MAXN];
bool visitado[MAXN];
int N, E;

int dijkstra(int origem, int destino) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visitado[i] = false;
    }
    dist[origem] = 0;

    for (int i = 1; i <= N; i++) {
        int u = -1;
        int menorDist = INF;

        for (int j = 1; j <= N; j++) {
            if (!visitado[j] && dist[j] < menorDist) {
                menorDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visitado[u] = true;
        if (u == destino) return dist[destino];

        for (int v = 1; v <= N; v++) {
            if (adj[u][v] != INF) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }
    return dist[destino];
}

int main() {
    int X, Y, H;
    int K, O, D;

    while (scanf("%d %d", &N, &E) && (N != 0 || E != 0)) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = INF;
            }
        }

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);
            if (adj[X][Y] > H) {
                adj[X][Y] = H;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][j] != INF && adj[j][i] != INF) {
                    adj[i][j] = 0;
                    adj[j][i] = 0;
                }
            }
        }

        scanf("%d", &K);
        while (K--) {
            scanf("%d %d", &O, &D);
            int resultado = dijkstra(O, D);

            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        printf("\n");
    }

    return 0;
}
