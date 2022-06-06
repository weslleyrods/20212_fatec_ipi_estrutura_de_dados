#include <stdio.h>
#include <stdlib.h>
#include "no.h"

typedef struct {
    int tamanho;
    s_no * primeiro;
    s_no * ultimo;
} t_fila;

void inicia_fila (t_fila *);
int esta_vazia (t_fila *);
void insere (int, t_fila *);
int remove_f (t_fila *);
void exibe_fila (t_fila *);

void passa_vez(t_fila *);

//Solução Machion
void passa_vez_ponteiro (t_fila *);
//Solução Machion
void passa_vez_info (t_fila *);
