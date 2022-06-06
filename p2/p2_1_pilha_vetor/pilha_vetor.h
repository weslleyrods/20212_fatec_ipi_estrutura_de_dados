#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_MAX 1000

typedef struct {
    int topo;
    int * dados;
} t_pilha;

void inicia_pilha (t_pilha *);

int esta_vazia (t_pilha *);
int esta_cheia (t_pilha *);

void push (int, t_pilha *);
int pop (t_pilha *);

void exibe_pilha (t_pilha *);

/*
1) (pilhas) Considere a estrutura pilha implementada sobre vetores e listas ligadas estudada em aulas. 

Considere agora o problema das Torres de Hanoi que não pode ter um valor maior empilhado sobre um valor menor.

Desenvolver uma função que recebe um elemento e faz o seu empilhamento, de acordo com a regra. 
Não manipule os dados internos da pilha, 
utilize somente as funções disponíveis. Você pode ter pilhas auxiliares nas suas funções para executar a tarefa.
Observação: fazer para as duas implementações.
*/

int retorna_topo(t_pilha*);
int hanoi(int, t_pilha*);

