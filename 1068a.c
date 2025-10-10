#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1001

typedef struct {
    char itens[MAX_TAMANHO];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX_TAMANHO - 1;
}

void empilhar(Pilha *p, char item) {
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = item;
    }
}

void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    }
}

const char* verificarParenteses(const char* expressao) {
    Pilha p;
    inicializarPilha(&p);
    int i;

    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar(&p, '(');
        } else if (expressao[i] == ')') {
            if (estaVazia(&p)) {
                return "incorrect";
            } else {
                desempilhar(&p);
            }
        }
    }

    if (estaVazia(&p)) {
        return "correct";
    } else {
        return "incorrect";
    }
}

int main() {
    char linha[MAX_TAMANHO + 1];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        linha[strcspn(linha, "\n")] = 0;
        
        if (strlen(linha) > 0) {
            const char* resultado = verificarParenteses(linha);
            printf("%s\n", resultado);
        }
    }

    return 0;
}
