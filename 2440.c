#include <stdio.h>
#include <string.h>

#define MAXN 50005
#define MAXM 200005

int head[MAXN];
int to[MAXM];
int next_edge[MAXM];
int edge_count;
int visitados[MAXN];

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count++;
}

void dfs(int u) {
    visitados[u] = 1;
    for (int i = head[u]; i != -1; i = next_edge[i]) {
        int v = to[i];
        if (!visitados[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N, M, u, v;
    
    scanf("%d %d", &N, &M);

    memset(head, -1, sizeof(head));
    memset(visitados, 0, sizeof(visitados));
    edge_count = 0;

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    int familias = 0;
    for (int i = 1; i <= N; i++) {
        if (!visitados[i]) {
            familias++;
            dfs(i);
        }
    }

    printf("%d\n", familias);

    return 0;
}
