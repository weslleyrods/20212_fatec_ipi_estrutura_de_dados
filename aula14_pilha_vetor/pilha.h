#include <stdio.h>
#include <stdlib.h>

//#define CAPACIDADE_MAX 1000;

typedef struct {
    int capacidade;
    int topo;
    int * dados;
} t_pilha;

void inicia_pilha(int, t_pilha *);

int esta_vazia(t_pilha *);
int esta_cheia(t_pilha *);

void push(int, t_pilha *);
int pop (t_pilha *);

void exibe_pilha(t_pilha*);

