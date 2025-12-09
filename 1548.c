#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, M, i;
    int notas[1005];
    int notas_ord[1005];

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &M);

        for (i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notas_ord[i] = notas[i];
        }

        qsort(notas_ord, M, sizeof(int), compare);

        int count = 0;
        for (i = 0; i < M; i++) {
            if (notas[i] == notas_ord[i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
