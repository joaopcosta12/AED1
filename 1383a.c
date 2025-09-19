#include <stdio.h>

int VerificadorSudoku(int conjunto[9]) {
    int contador[9] = {0};
    for (int i = 0; i < 9; i++) {
        if (conjunto[i] < 1 || conjunto[i] > 9) {
            return 0;
        }
        if (++contador[conjunto[i] - 1] > 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 0, instancia;
    scanf("%d", &instancia);

    while (n < instancia) {
        int matriz[9][9];
        int solucao = 1;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            if (VerificadorSudoku(matriz[i]) == 0) {
                solucao = 0;
                break;
            }
        }

        if (solucao) {
            for (int j = 0; j < 9; j++) {
                int coluna_atual[9];
                for (int i = 0; i < 9; i++) {
                    coluna_atual[i] = matriz[i][j];
                }
                if (VerificadorSudoku(coluna_atual) == 0) {
                    solucao = 0;
                    break;
                }
            }
        }

        if (solucao) {
            for (int linha_base = 0; linha_base < 9; linha_base += 3) {
                for (int coluna_base = 0; coluna_base < 9; coluna_base += 3) {
                    int regiao_atual[9];
                    int k = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            regiao_atual[k] = matriz[linha_base + i][coluna_base + j];
                            k++;
                        }
                    }
                    if (VerificadorSudoku(regiao_atual) == 0) {
                        solucao = 0;
                        break;
                    }
                }
                if (!solucao) {
                    break;
                }
            }
        }
        
        printf("Instancia %d\n", n + 1);
        if (solucao) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
        
        n++;
    }

    return 0;
}