#include "no_bin.h"

struct arvore{
    int n_nos;
    struct no_bin * raiz;
};

void inicializa_arvore(struct arvore *);

int arvore_vazia(struct arvore * );

void insere (int, struct arvore *);

void mostra_em_ordem(struct arvore *);