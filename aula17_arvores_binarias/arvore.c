#include "arvore.h"

void inicializa_arvore(struct arvore *a){
    a->n_nos =0;
    a->raiz = NULL;
}

int arvore_vazia(struct arvore * a){
        return !a->raiz;
        
        //return a->raiz == NULL;
}


void insere_rec(int i, struct no_bin * atual){
    if(i <= atual->info){//vai para a esquerda
        if(atual->esq ==NULL){
            atual->esq = cria_no_bin(i);
        }
        else{
            insere_rec(i, atual->esq);
        }
    }
    else{//vai para a direita
        if(atual->dir ==NULL){
            atual->dir = cria_no_bin(i);
        }
        else{
            insere_rec(i, atual->dir);
        }
    }
}

void insere (int i, struct arvore *a){
   struct no_bin * novo = cria_no_bin(i);
        a->n_nos++;
    if(arvore_vazia(a)){
        a->raiz = novo; //Outra forma: a->raiz = cria_no_bin(i);
    }
    else{
        insere_rec(i, a->raiz);

    }
}

void mostra_em_ordem_rec (struct no_bin * atual){
    if(atual != NULL){
        mostra_em_ordem_rec(atual->esq);
        printf("%d ", atual->info);
        mostra_em_ordem_rec(atual->dir);
    }
}

void mostra_em_ordem(struct arvore *a){
    if(arvore_vazia(a)){
        printf ("Arvore vazia \n");
    }
    else{
        mostra_em_ordem_rec (a->raiz);
    }
}

