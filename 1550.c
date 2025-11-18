#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALOR 10001

int fila[MAX_VALOR];
int inicio, fim;
int distancia[MAX_VALOR];

int reverter(int n) {
    int revertido = 0;
    while (n > 0) {
        revertido = revertido * 10 + (n % 10);
        n /= 10;
    }
    return revertido;
}

int resolver_bfs(int A, int B) {
    inicio = 0;
    fim = 0;
    
    memset(distancia, -1, sizeof(distancia));

    distancia[A] = 0;
    fila[fim++] = A;

    while (inicio < fim) {
        int atual = fila[inicio++];

        if (atual == B) {
            return distancia[B];
        }

        int vizinho_soma = atual + 1;
        
        if (vizinho_soma < MAX_VALOR && distancia[vizinho_soma] == -1) {
            distancia[vizinho_soma] = distancia[atual] + 1;
            fila[fim++] = vizinho_soma;
        }

        int vizinho_reverso = reverter(atual);
        
        if (vizinho_reverso < MAX_VALOR && distancia[vizinho_reverso] == -1) {
            distancia[vizinho_reverso] = distancia[atual] + 1;
            fila[fim++] = vizinho_reverso;
        }
    }
    
    return -1; 
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", resolver_bfs(A, B));
    }
    
    return 0;
}
