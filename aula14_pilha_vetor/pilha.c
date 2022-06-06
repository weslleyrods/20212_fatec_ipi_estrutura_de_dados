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
        printf("%d", p->dados[i]);

    printf("\n");
}

//~ EXERCICIOS ~
	
//1. Considerando a pilha sobre vetores, implementar com topo iniciando em -1
//2. Considerando a pilha sobre listas ligadas, acrescentar à estrutura 
//um atributo que contém o número de elementos na pilha e refatorar o código.