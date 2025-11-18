#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* proximo;
} No;

void inserir_no_final(No** cabeca, int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }

    No* atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novoNo;
}

void liberar_lista(No* cabeca) {
    No* atual = cabeca;
    No* temporario;
    while (atual != NULL) {
        temporario = atual;
        atual = atual->proximo;
        free(temporario);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int M, C;
        scanf("%d %d", &M, &C);

        No* tabelaHash[100];

        for (int j = 0; j < M; j++) {
            tabelaHash[j] = NULL;
        }

        for (int j = 0; j < C; j++) {
            int chave;
            scanf("%d", &chave);
            
            int indice = chave % M;
            
            inserir_no_final(&tabelaHash[indice], chave);
        }

        for (int j = 0; j < M; j++) {
            printf("%d -> ", j);
            No* atual = tabelaHash[j];
            
            while (atual != NULL) {
                printf("%d -> ", atual->chave);
                atual = atual->proximo;
            }
            printf("\\\n");
        }

        for (int j = 0; j < M; j++) {
            liberar_lista(tabelaHash[j]);
        }

        if (i < N - 1) {
            printf("\n");
        }
    }

    return 0;
}
