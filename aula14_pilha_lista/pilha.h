#include <stdio.h>
#include <stdlib.h>
#include "no.h"

typedef struct {

    s_no * topo;
}t_pilha;

void inicia_pilha(t_pilha *);
int esta_vazia(t_pilha *);
void push(int, t_pilha * );
int pop(t_pilha *);
void exibe_pilha (t_pilha *);




//1. Para as 2 implementações da pilha, implementar uma função para resolver as tarefas a seguir:

//1. Devolver o tamanho da pilha
//2. Verificr se 2 pilhas são iguais
//3. Encontrar o maior elemento empilhados
