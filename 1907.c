#include <stdio.h>

#define MAX 1026

char grid[MAX][MAX];
int N, M;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

typedef struct { int r, c; } Ponto;
Ponto pilha[MAX * MAX];
int topo;

void push(int r, int c) {
    pilha[topo].r = r;
    pilha[topo].c = c;
    topo++;
}

void flood_fill(int r, int c) {
    topo = 0;
    push(r, c);
    grid[r][c] = 'o';

    while (topo > 0) {
        Ponto atual = pilha[--topo];
        
        for (int i = 0; i < 4; i++) {
            int nr = atual.r + dr[i];
            int nc = atual.c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == '.') {
                grid[nr][nc] = 'o';
                push(nr, nc);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int clicks = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') {
                clicks++;
                flood_fill(i, j);
            }
        }
    }

    printf("%d\n", clicks);
    return 0;
}
