#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 501

typedef struct {
    int items[MAX_SIZE];
    int inicio;
    int fim;
    int qtd;
} Baralho;

void inicializar(Baralho *b) {
    b->inicio = 0;
    b->fim = 0;
    b->qtd = 0;
}

int estaCheia(Baralho *b) {
    return b->qtd == MAX_SIZE;
}

int estaVazia(Baralho *b) {
    return b->qtd == 0;
}

void enfileirar(Baralho *b, int valor) {
    if (estaCheia(b)) {
        return;
    }
    b->items[b->fim] = valor;
    b->fim = (b->fim + 1) % MAX_SIZE;
    b->qtd++;
}

int desenfileirar(Baralho *b) {
    if (estaVazia(b)) {
        return -1;
    }
    int item = b->items[b->inicio];
    b->inicio = (b->inicio + 1) % MAX_SIZE;
    b->qtd--;
    return item;
}

int main() {
    Baralho Cartas;
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {

        inicializar(&Cartas);

        for (int i = 1; i <= n; i++) {
            enfileirar(&Cartas, i);
        }
        
        int removidos[MAX_SIZE];
        int indiceRemovidos = 0;

        while (Cartas.qtd > 1) {
            int eliminado = desenfileirar(&Cartas);
            if (eliminado != -1) {
                removidos[indiceRemovidos] = eliminado;
                indiceRemovidos++;
            }

            int movido = desenfileirar(&Cartas);
            if (movido != -1) {
                enfileirar(&Cartas, movido);
            }
        }

        int ultimo = desenfileirar(&Cartas);
        
        printf("Discarded cards:");
        for (int i = 0; i < indiceRemovidos; i++) {
            if (i == 0) {
                 printf(" %d", removidos[i]);
            } else {
                 printf(", %d", removidos[i]);
            }
        }
        printf("\n");
        
        printf("Remaining card: %d\n", ultimo);
    }

    return 0;
}
