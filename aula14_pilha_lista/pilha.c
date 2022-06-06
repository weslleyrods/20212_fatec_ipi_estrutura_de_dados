#include "pilha.h"


void inicia_pilha(t_pilha *p){
    p->topo = NULL;
}
int esta_vazia(t_pilha *p){
    return !p->topo;
}
void push(int i, t_pilha * p){
    s_no * novo = constroi_no(i);
    if (!esta_vazia(p))
        novo->proximo = p->topo;
    p->topo = novo;
}
int pop(t_pilha * p){
    int aux = p->topo->info;
    s_no * temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return aux;
}
void exibe_pilha (t_pilha * p){
    s_no * aux;
    if (esta_vazia(p))
        printf("Pilha vazia");
    else{
        aux = p->topo;
        while (aux){//enquanto verdadeiro, ou seja, aux diferente de NULL
            //DESAFIO FOR
            printf ("%d", aux->info);
            aux = aux ->proximo;
        }
        printf ("\n");
    }
}

//~ EXERCICIOS ~
	
//1. Considerando a pilha sobre vetores, implementar com topo iniciando em -1
//2. Considerando a pilha sobre listas ligadas, acrescentar à estrutura 
//um atributo que contém o número de elementos na pilha e refatorar o código.