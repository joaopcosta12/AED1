#include <stdio.h>
#include <string.h>

int pilha[1005], topo;
int fila[1005], ini, fim;
int pq[1005], pq_tam;

void push_st(int x) { pilha[topo++] = x; }
void pop_st() { if(topo > 0) topo--; }
int top_st() { return (topo > 0) ? pilha[topo-1] : -1; }

void push_q(int x) { fila[fim++] = x; }
void pop_q() { if(ini < fim) ini++; }
int front_q() { return (ini < fim) ? fila[ini] : -1; }

void push_pq(int x) { pq[pq_tam++] = x; }
int pop_pq() {
    int maior = -1, idx = -1;
    for(int i = 0; i < pq_tam; i++) {
        if(pq[i] > maior) {
            maior = pq[i];
            idx = i;
        }
    }
    if(idx != -1) {
        pq[idx] = pq[pq_tam-1];
        pq_tam--;
    }
    return maior;
}

int main() {
    int N, tipo, x;
    
    while(scanf("%d", &N) != EOF) {
        topo = 0;
        ini = 0; fim = 0;
        pq_tam = 0;
        
        int is_st = 1, is_q = 1, is_pq = 1;
        
        for(int i = 0; i < N; i++) {
            scanf("%d %d", &tipo, &x);
            
            if(tipo == 1) {
                if(is_st) push_st(x);
                if(is_q) push_q(x);
                if(is_pq) push_pq(x);
            } else {
                if(is_st) {
                    if(topo == 0 || top_st() != x) is_st = 0;
                    else pop_st();
                }
                if(is_q) {
                    if(ini == fim || front_q() != x) is_q = 0;
                    else pop_q();
                }
                if(is_pq) {
                    if(pq_tam == 0 || pop_pq() != x) is_pq = 0;
                }
            }
        }
        
        if(is_st && !is_q && !is_pq) printf("stack\n");
        else if(!is_st && is_q && !is_pq) printf("queue\n");
        else if(!is_st && !is_q && is_pq) printf("priority queue\n");
        else if(!is_st && !is_q && !is_pq) printf("impossible\n");
        else printf("not sure\n");
    }
    return 0;
}
