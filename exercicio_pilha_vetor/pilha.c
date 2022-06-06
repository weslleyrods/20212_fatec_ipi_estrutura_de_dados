#include "pilha.h"

void inicia_pilha(int capacidade, t_pilha *p){
    p->dados = (int *) malloc (capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade;
}

int esta_vazia(t_pilha *p){
    return !p->topo;
    
}
int esta_cheia(t_pilha *p){
    return p->topo == p->capacidade;
}

void push(int i, t_pilha *p){
    p->dados[p->topo++] = i;
}

int pop (t_pilha *p){
    return p->dados[--p->topo];
}

void exibe_pilha(t_pilha *p){
    if(esta_vazia(p))
    printf ("Pilha vazia");
    else
    for (int i = p->topo-1; i >=0; i--)
        printf("%d ", p->dados[i]);

    printf("\n");
}

//1. Devolver o tamanho da pilha
int tamanho_pilha(t_pilha *p) {
    return p->topo;
}

int compara_pilhas(t_pilha* p1, t_pilha* p2) {
    if ( tamanho_pilha(p1) != tamanho_pilha(p2) ) return FALSE;
    int i = 0;
    while ( p1->dados[i] == p2->dados[i] && i <  tamanho_pilha(p1))
        i++;
    return tamanho_pilha(p1) == i;
}

int compara_pilhas_dois(t_pilha* p1, t_pilha* p2) {
    if(tamanho_pilha(p1) == tamanho_pilha(p2)){ 
        for(int i = 0; i < p1->topo; i++){ //qlqr uma do vetor para percorrer, já que os tamanhos são iguais
            if (p1->dados[i] != p2->dados[i]) return FALSE;
        }return TRUE;
    }
    return FALSE;
}


int maior_elemento_pilha(t_pilha *p) {
    int maior;
    for(int i = 0; i < tamanho_pilha(p)-1; i++) {
        if (p->dados[i] > p->dados[i+1])
            maior = p->dados[i];
    }
    return maior;
}

int maior_elemento_pilha_dois(t_pilha *p) {
    int maior = p->dados[0];
    for(int i = 1; i < tamanho_pilha(p); i++) {
        if (p->dados[i] > maior)
            maior = p->dados[i];
    }

    return maior;
}