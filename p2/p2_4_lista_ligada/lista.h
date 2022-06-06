#include "no.h"

#define SUCESSO 1
#define FRACASSO 0

typedef struct lista {
    struct no * primeiro;
} s_lista;

void constroi_lista (s_lista *);

int esta_vazia (s_lista *);

int insere_inicio (int, s_lista *);

void mostra_lista (char *, s_lista *);

int insere_fim (int, s_lista *);

int remove_inicio (s_lista *);

int remove_fim (s_lista *);

s_lista * remove_par(s_lista *);

//Solução Machion
void remove_pares (s_lista *);

