#include <stdio.h>
#include <stdlib.h>

void Insercao(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--) {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main() {
    int nc;
    scanf("%d", &nc);

    for (int k = 0; k < nc; k++) {
        int n;
        scanf("%d", &n);

        int *alturas = (int *)malloc(n * sizeof(int));

        if (alturas == NULL) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            scanf("%d", &alturas[j]);
        }

        Insercao(n, alturas);

        for (int j = 0; j < n; j++) {
            printf("%d", alturas[j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
