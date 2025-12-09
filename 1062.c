#include <stdio.h>
#include <stdlib.h>

int pilha[1005];
int topo;

void push(int valor) {
    pilha[topo++] = valor;
}

void pop() {
    if (topo > 0) topo--;
}

int top() {
    if (topo > 0) return pilha[topo - 1];
    return -1;
}

int empty() {
    return topo == 0;
}

int main() {
    int N;
    int alvo[1005];

    while (scanf("%d", &N) && N != 0) {
        while (1) {
            scanf("%d", &alvo[0]);
            if (alvo[0] == 0) {
                printf("\n");
                break;
            }
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            topo = 0;
            int entrada = 1;
            int idx = 0;
            int ok = 1;

            while (idx < N) {
                if (entrada <= N && (empty() || top() != alvo[idx])) {
                    push(entrada++);
                } 
                else if (!empty() && top() == alvo[idx]) {
                    pop();
                    idx++;
                } 
                else {
                    ok = 0;
                    break;
                }
            }

            if (ok) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
