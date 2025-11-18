#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOTAL_CARACTERES 1000002
#define MAX_NUMERO_JOIAS 1000001

int comparar_ponteiros(const void *a, const void *b) {
    char* str_a = *(char**)a;
    char* str_b = *(char**)b;
    return strcmp(str_a, str_b);
}

int main() {
    char* buffer_total = malloc(MAX_TOTAL_CARACTERES);
    char** ponteiros_joias = malloc(MAX_NUMERO_JOIAS * sizeof(char*));

    if (buffer_total == NULL || ponteiros_joias == NULL) {
        return 1;
    }

    char* buffer_atual = buffer_total;
    int total_joias = 0;
    int quantidade_distinta = 0;
    
    while (fgets(buffer_atual, MAX_TOTAL_CARACTERES, stdin) != NULL) {
        
        size_t len = strlen(buffer_atual);
        if (len > 0 && buffer_atual[len - 1] == '\n') {
            buffer_atual[len - 1] = '\0';
        }

        if (strlen(buffer_atual) == 0 && feof(stdin) == 0) {
            continue;
        }

        ponteiros_joias[total_joias] = buffer_atual;
        total_joias++;

        buffer_atual += strlen(buffer_atual) + 1;

        if (buffer_atual - buffer_total > MAX_TOTAL_CARACTERES - 2) {
            break;
        }
        if (total_joias >= MAX_NUMERO_JOIAS) {
            break;
        }
    }

    if (total_joias == 0) {
        printf("0\n");
        free(buffer_total);
        free(ponteiros_joias);
        return 0;
    }

    qsort(ponteiros_joias, total_joias, sizeof(char*), comparar_ponteiros);

    quantidade_distinta = 1;
    for (int i = 1; i < total_joias; i++) {
        if (strcmp(ponteiros_joias[i], ponteiros_joias[i - 1]) != 0) {
            quantidade_distinta++;
        }
    }

    printf("%d\n", quantidade_distinta);

    free(buffer_total);
    free(ponteiros_joias);

    return 0;
}
