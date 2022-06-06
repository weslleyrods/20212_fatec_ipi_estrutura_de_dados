#include <stdio.h>
#include <stdlib.h>

//#define CAPACIDADE_MAX 1000;
#define FALSE 0;
#define TRUE 1;

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

void exibe_pilha(t_pilha *);

//ENTREGA

//1. Para as 2 implementações da pilha, implementar uma função para resolver as tarefas a seguir:


//prototipos
//1. Devolver o tamanho da pilha
int tamanho_pilha (t_pilha *);

//2. Verificar se 2 pilhas são iguais
int compara_pilhas(t_pilha *, t_pilha *);

//3. Encontrar o maior elemento empilhado
int maior_elemento(t_pilha *);
