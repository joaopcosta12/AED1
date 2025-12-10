#include <stdio.h>

typedef struct {
    int chegada, saida;
} Carro;

Carro pilha[100005];
int topo;

int main() {
    int N, K;
    int c, s;

    while (scanf("%d %d", &N, &K) && (N || K)) {
        topo = 0;
        int possivel = 1;

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &c, &s);

            if (!possivel) continue;

            while (topo > 0 && pilha[topo - 1].saida <= c) {
                topo--;
            }

            if (topo >= K) {
                possivel = 0;
            } else {
                if (topo > 0 && pilha[topo - 1].saida < s) {
                    possivel = 0;
                } else {
                    pilha[topo].chegada = c;
                    pilha[topo].saida = s;
                    topo++;
                }
            }
        }

        if (possivel) printf("Sim\n");
        else printf("Nao\n");
    }

    return 0;
}
