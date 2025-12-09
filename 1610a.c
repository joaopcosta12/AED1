#include <stdio.h>
#include <string.h>

#define MAXN 10005
#define MAXM 50005

int head[MAXN];
int to[MAXM];
int next_edge[MAXM];
int edge_count;
int visitados[MAXN];
int flag_ciclo;

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count++;
}

void dfs(int u) {
    visitados[u] = 1;
    for(int i = head[u]; i != -1; i = next_edge[i]) {
        int v = to[i];
        if(visitados[v] == 1) {
            flag_ciclo = 1;
            return;
        }
        if(visitados[v] == 0) {
            dfs(v);
            if(flag_ciclo) return;
        }
    }
    visitados[u] = 2;
}

int main() {
    int T, N, M, u, v;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d %d", &N, &M);
        
        memset(head, -1, sizeof(int) * (N + 1));
        memset(visitados, 0, sizeof(int) * (N + 1));
        edge_count = 0;
        flag_ciclo = 0;
        
        for(int i = 0; i < M; i++) {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }
        
        for(int i = 1; i <= N; i++) {
            if(visitados[i] == 0) {
                dfs(i);
                if(flag_ciclo) break;
            }
        }
        
        if(flag_ciclo) printf("SIM\n");
        else printf("NAO\n");
    }
    return 0;
}
