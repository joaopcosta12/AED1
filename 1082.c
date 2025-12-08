#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grafo[30][30];
int visitados[30];
int lista[30];
int tam;
int V;

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int u) {
    visitados[u] = 1;
    lista[tam++] = u;
    
    for (int v = 0; v < V; v++) {
        if (grafo[u][v] && !visitados[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N, E, i, j, caso = 1;
    char u, v;
    
    scanf("%d", &N);

    while (N--) {
        scanf("%d %d", &V, &E);

        memset(grafo, 0, sizeof(grafo));
        memset(visitados, 0, sizeof(visitados));

        for (i = 0; i < E; i++) {
            scanf(" %c %c", &u, &v);
            grafo[u-'a'][v-'a'] = 1;
            grafo[v-'a'][u-'a'] = 1;
        }

        printf("Case #%d:\n", caso++);
        int componentes = 0;

        for (i = 0; i < V; i++) {
            if (!visitados[i]) {
                tam = 0;
                dfs(i);
                
                qsort(lista, tam, sizeof(int), cmp);
                
                for(j = 0; j < tam; j++) {
                    printf("%c,", lista[j] + 'a');
                }
                printf("\n");
                componentes++;
            }
        }
        printf("%d connected components\n\n", componentes);
    }
    return 0;
}
