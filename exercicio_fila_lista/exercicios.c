#include "fila.h"


void inicia_fila(t_fila *f){
    f->tamanho = 0;
    f->primeiro = f->ultimo = NULL; //igualdade transitiva
}
int esta_vazia(t_fila *f){
    return !f->tamanho;
}


void insere(int i, t_fila *f){
    s_no * novo = constroi_no(i);
    if(esta_vazia(f)){
        f->primeiro = novo;
    }
    else{
        f->ultimo->proximo = novo;
    }
    f->ultimo = novo;
    f->tamanho++;
}
int remove_f(t_fila *f){
    s_no * aux = f->primeiro;
    int aux_info = f->primeiro->info;
    f->primeiro = f->primeiro->proximo;
    f->tamanho--;
    if(esta_vazia(f)) f->ultimo == NULL;
    free(aux);
    return aux_info;
}


 void exibe_fila (t_fila * f){
    s_no * aux;
    if (esta_vazia(f))
        printf("Fila vazia");
    else{
        aux = f->primeiro;
        while (aux){
            printf ("%d", aux->info);
            aux = aux ->proximo;
        }
    }
    printf ("\n");
}