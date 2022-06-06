#include "pilha_lista.h"

void inicia_pilha (t_pilha *p) {
    p->topo = NULL;
}
int esta_vazia (t_pilha *p) {
    return !p->topo;
}
void push (int i, t_pilha *p) {
    s_no * novo = constroi_no(i);
    if (!esta_vazia(p)) 
        novo->proximo = p->topo;
    p->topo = novo;
}
int pop (t_pilha *p) {
    int aux = p->topo->info;
    s_no * temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return aux;
}
void exibe_pilha (t_pilha *p) {
    s_no * aux;
    if (esta_vazia(p))
        printf ("pilha vazia");
    else {
        aux = p->topo;
        while (aux) {
            printf ("%d ", aux->info);
            aux = aux->proximo;
        }
    }
    printf ("\n");
}

int retorna_topo(t_pilha*p){
    return p->topo->info;
}

int hanoi(int numero, t_pilha*p){
    t_pilha aux;  
    inicia_pilha(&aux); 
    if(!esta_vazia(p)){
        if(retorna_topo(p) >= numero){
            push(numero, p);
        }
        else{
            while(!esta_vazia(p) && numero > retorna_topo(p)){
                push(pop(p), &aux); //coloca o respectivo topo na pilha auxiliar
            }    
                push(numero, p); //encaixa o número na lista original   
            while(!esta_vazia(&aux)){              
                push(pop(&aux), p); //colocar de volta na caixa
            }     
        }   
    }
    else
        push(numero, p);
}

//Hanoi da Machion
void push_hanoi (int i, t_pilha *p) {
t_pilha pilha_aux;
inicia_pilha(&pilha_aux);
while (!esta_vazia(p) && retorna_topo(p) < i)
push(pop(p), &pilha_aux);
push (i, p);
while (!esta_vazia(&pilha_aux))
push(pop(&pilha_aux), p);
}