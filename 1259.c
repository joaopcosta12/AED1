#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    int A = *(int*)a;
    int B = *(int*)b;

    if (A % 2 == 0 && B % 2 != 0) return -1;
    if (A % 2 != 0 && B % 2 == 0) return 1;
    
    if (A % 2 == 0) return A - B;
    return B - A;
}

int main() {
    int N, i;
    int valores[100005];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &valores[i]);
    }

    qsort(valores, N, sizeof(int), comp);

    for (i = 0; i < N; i++) {
        printf("%d\n", valores[i]);
    }

    return 0;
}
