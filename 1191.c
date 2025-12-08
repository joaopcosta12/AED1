#include <stdio.h>
#include <string.h>

char prefixa[1000];
char infixa[1000];
int indice_prefixa;

void posfixa_recursiva(int inicio, int fim) {
    if (inicio > fim) {
        return;
    }

    char raiz = prefixa[indice_prefixa];
    indice_prefixa++;

    int pos_na_infixa = -1;
    for (int i = inicio; i <= fim; i++) {
        if (infixa[i] == raiz) {
            pos_na_infixa = i;
            break;
        }
    }

    posfixa_recursiva(inicio, pos_na_infixa - 1);
    posfixa_recursiva(pos_na_infixa + 1, fim);

    printf("%c", raiz);
}

int main() {
    while (scanf("%s %s", prefixa, infixa) != EOF) {
        int n = strlen(prefixa);
        indice_prefixa = 0;

        posfixa_recursiva(0, n - 1);
        printf("\n");
    }

    return 0;
}
