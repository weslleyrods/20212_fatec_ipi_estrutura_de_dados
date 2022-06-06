#include <stdio.h>
#include <stdlib.h>
#include "no.h"

typedef struct {
    s_no * topo;
} t_pilha;

void inicia_pilha (t_pilha *);
int esta_vazia (t_pilha *);
void push (int, t_pilha *);
int pop (t_pilha *);

void exibe_pilha (t_pilha *);

int retorna_topo(t_pilha *);

int hanoi(int , t_pilha *);

void push_hanoi (int , t_pilha *);