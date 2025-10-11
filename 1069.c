#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char mina[1001];
        scanf("%s", mina);

        int diamantes = 0;
        int abertos = 0;

        for (int i = 0; i < strlen(mina); i++) {
            if (mina[i] == '<') {
                abertos++;
            }
            else if (mina[i] == '>') {
                if (abertos > 0) {
                    diamantes++;
                    abertos--;
                }
            }
        }
        printf("%d\n", diamantes);
    }

    return 0;
}
