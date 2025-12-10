#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cor[20];
    char tamanho;
} Camiseta;

Camiseta lista[65];

int cmp(const void *a, const void *b) {
    Camiseta *c1 = (Camiseta*)a;
    Camiseta *c2 = (Camiseta*)b;

    int r = strcmp(c1->cor, c2->cor);
    if (r != 0) return r;

    if (c1->tamanho != c2->tamanho)
        return c2->tamanho - c1->tamanho; 

    return strcmp(c1->nome, c2->nome);
}

int main() {
    int N, first = 1;
    char buffer[100];

    while (scanf("%d", &N) && N != 0) {
        fgets(buffer, 100, stdin); 

        if (!first) printf("\n");
        first = 0;

        for (int i = 0; i < N; i++) {
            fgets(lista[i].nome, 100, stdin);
            lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
            
            scanf("%s %c", lista[i].cor, &lista[i].tamanho);
            fgets(buffer, 100, stdin); 
        }

        qsort(lista, N, sizeof(Camiseta), cmp);

        for (int i = 0; i < N; i++) {
            printf("%s %c %s\n", lista[i].cor, lista[i].tamanho, lista[i].nome);
        }
    }
    return 0;
}
