#include <stdio.h>

#define MAX 1000005

typedef struct {
    int valor;
    int min_atual;
} No;

No pilha[MAX];
int topo = 0;

void push(int v) {
    pilha[topo].valor = v;
    if (topo == 0) {
        pilha[topo].min_atual = v;
    } else {
        int anterior = pilha[topo - 1].min_atual;
        pilha[topo].min_atual = (v < anterior) ? v : anterior;
    }
    topo++;
}

void pop() {
    if (topo > 0) {
        topo--;
    } else {
        printf("EMPTY\n");
    }
}

void min() {
    if (topo > 0) {
        printf("%d\n", pilha[topo - 1].min_atual);
    } else {
        printf("EMPTY\n");
    }
}

int main() {
    int N, v;
    char op[10];

    scanf("%d", &N);

    while (N--) {
        scanf("%s", op);
        if (op[1] == 'U') { // PUSH
            scanf("%d", &v);
            push(v);
        } else if (op[1] == 'O') { // POP
            pop();
        } else { // MIN
            min();
        }
    }
    return 0;
}
