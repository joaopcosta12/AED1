#include <stdio.h>
#include <string.h>

#define MAX_ID 100005
#define MAX_N 50005

int fila[MAX_N];
int saiu[MAX_ID];

int main() {
    int N, M, id, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    memset(saiu, 0, sizeof(saiu));

    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &id);
        saiu[id] = 1;
    }

    int first = 1;
    for (i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (!first) printf(" ");
            printf("%d", fila[i]);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
