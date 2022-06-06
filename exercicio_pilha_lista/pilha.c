#include "pilha.h"

void inicia_pilha(t_pilha *p){
    p->topo = NULL;
}

int esta_vazia(t_pilha *p){

    // return p->topo == NULL;
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
            printf ("%d ", aux->info);
            aux = aux ->proximo;
        }
        printf ("\n");
    }
}

//1. Devolver o tamanho da pilha;
int tamanho_pilha(t_pilha *p){
    int contador = 1;
    if (esta_vazia(p)) return 0;
    if (p->topo->proximo == NULL) return 1;
    s_no * aux = p->topo;
    while (aux->proximo != NULL){
        aux = aux->proximo; //aux percorre a lista, se subescrevendo
        contador++;
    }
    return contador;
}

//2. Verificar se 2 pilhas são iguais;
int compara_pilha(t_pilha *p1, t_pilha*p2){
    if (tamanho_pilha(p1) != tamanho_pilha(p2)) return 0;
    s_no * aux1, * aux2;
    aux1 = p1->topo;
    aux2 = p2->topo;
    int contador = 0;

    while (aux1->info == aux2->info && aux1->proximo != NULL) {        
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }

    return !aux1->proximo && aux1->info == aux2->info; 
}

//2. Versão simplificada
int compara_pilha_dois(t_pilha *p1, t_pilha*p2){
    if (tamanho_pilha(p1) != tamanho_pilha(p2)) return 0;
    s_no * aux1, * aux2;
    aux1 = p1->topo;
    aux2 = p2->topo;
    while (aux1 != NULL && aux1->info == aux2->info) {        
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }
    return !aux1;
}

//3. Encontrar o maior elemento empilhado.
int maior_pilha(t_pilha * p){
    s_no * aux = p->topo; //start
    int maior = p->topo->info;
    while(aux){
        if(aux->info > maior)
            maior = aux->info;
        aux = aux->proximo; //percorre a lista
    }
    return maior;
}

int maior_pilha_dois(t_pilha * p){
    int maior = p->topo->info;
    for (s_no * aux = p->topo; aux != NULL; aux = aux->proximo) {
        if(aux->info > maior)
            maior = aux->info;
    }
    return maior;
}





