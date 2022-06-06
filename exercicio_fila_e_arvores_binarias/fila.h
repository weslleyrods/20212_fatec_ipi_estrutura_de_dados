#include <stdio.h>
#include <stdlib.h>
#include "no.h"

typedef struct {
    int tamanho;
    s_no * primeiro;
    s_no * ultimo;
}t_fila;

void inicia_fila(t_fila *);

int esta_vazia(t_fila *);
void insere(int, t_fila * );
int remove_f(t_fila *);
void exibe_fila (t_fila *);

int tamanho_fila(t_fila *);

int compara_fila(t_fila *, t_fila *);

void merge_fila(t_fila *, t_fila *, t_fila *);