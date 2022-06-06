#include "pilha_vetor.h"

void inicia_pilha (t_pilha *p) {
    p->dados = (int *) malloc (CAPACIDADE_MAX * sizeof(int));
    p->topo = 0;
}
int esta_vazia (t_pilha *p) {
    return !p->topo;
}
int esta_cheia (t_pilha *p) {
    return p->topo == CAPACIDADE_MAX;
}
void push (int i, t_pilha *p) {
    p->dados[p->topo++] = i;
}
int pop (t_pilha *p) {
    return p->dados[--p->topo];
}
void exibe_pilha (t_pilha *p) {
    int i;
    if (esta_vazia(p))
        printf ("pilha vazia");
    else 
        for (i=p->topo-1; i>=0; i--) 
            printf ("%d ", p->dados[i]);
    printf ("\n");
}

int retorna_topo(t_pilha*p){
    return p->dados[p->topo-1];
}

int hanoi(int numero, t_pilha*p){
    t_pilha aux;  
    inicia_pilha(&aux); 
    if(!esta_vazia(p)){
        if(retorna_topo(p) >= numero){
            push(numero, p);
        }
        else{
            while(retorna_topo(p) < numero){
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