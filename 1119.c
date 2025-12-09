#include <stdio.h>

int main() {
    int N, k, m, i;
    int fila[25];

    while (scanf("%d %d %d", &N, &k, &m) && N != 0) {
        for (i = 0; i < N; i++) fila[i] = i + 1;

        int restantes = N;
        int p1 = -1, p2 = N; // Posições iniciais virtuais

        while (restantes > 0) {
            int conta = 0;
            
            // Move sentido horário (k)
            while (conta < k) {
                p1 = (p1 + 1) % N;
                if (fila[p1] != 0) conta++;
            }

            conta = 0;
            // Move sentido anti-horário (m)
            while (conta < m) {
                p2 = (p2 - 1 + N) % N;
                if (fila[p2] != 0) conta++;
            }

            if (restantes < N) printf(",");
            
            if (p1 != p2) {
                printf("%3d%3d", fila[p1], fila[p2]);
                fila[p1] = 0;
                fila[p2] = 0;
                restantes -= 2;
            } else {
                printf("%3d", fila[p1]);
                fila[p1] = 0;
                restantes--;
            }
        }
        printf("\n");
    }
    return 0;
}
