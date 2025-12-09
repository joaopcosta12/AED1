#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int busca_primeira(int *vetor, int n, int alvo) {
    int inicio = 0, fim = n - 1;
    int index = -1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == alvo) {
            index = meio;
            fim = meio - 1; 
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return index;
}

int main() {
    int N, Q, i, caso = 1, consulta, pos;
    int *marmores;

    while (scanf("%d %d", &N, &Q) && (N != 0 || Q != 0)) {
        marmores = (int*)malloc(N * sizeof(int));
        
        for (i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }

        qsort(marmores, N, sizeof(int), compare);

        printf("CASE# %d:\n", caso++);
        for (i = 0; i < Q; i++) {
            scanf("%d", &consulta);
            pos = busca_primeira(marmores, N, consulta);
            
            if (pos != -1) {
                printf("%d found at %d\n", consulta, pos + 1);
            } else {
                printf("%d not found\n", consulta);
            }
        }
        
        free(marmores);
    }
    return 0;
}
