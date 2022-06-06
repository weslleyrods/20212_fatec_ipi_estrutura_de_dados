#include "fila.h"

void inicia_fila (t_fila *f) {
    f->tamanho = 0;
    f->primeiro = NULL;
    f->ultimo = NULL;
}
int esta_vazia (t_fila *f) {
    return !f->tamanho;
}

void insere (int i, t_fila *f) {
    s_no * novo = constroi_no(i);
    if (esta_vazia(f)) {
        f->primeiro = novo;
    }
    else {
        f->ultimo->proximo = novo;
    }
    f->ultimo = novo;
    f->tamanho++;
}

int remove_f (t_fila *f){
    s_no * aux_end = f->primeiro;
    int aux_info = f->primeiro->info;
    f->primeiro = f->primeiro->proximo;
    f->tamanho--;
    if (esta_vazia(f)) f->ultimo = NULL;
    free(aux_end);
    return aux_info;
}
void exibe_fila (t_fila * f){
    s_no * aux;
    if (esta_vazia(f))
        printf("Fila vazia");
    else{
        aux = f->primeiro;
        while (aux){
            printf ("%d ", aux->info);
            aux = aux ->proximo;
        }
    }
    printf ("\n");
}

void passa_vez(t_fila *f){
    s_no * aux, * aux2, * aux3;
    if(f->primeiro != f->ultimo){
        if(!esta_vazia(f)){
            aux = f->primeiro;// 1º lugar (cópia)
            aux3 = f->primeiro->proximo->proximo;
            f->primeiro = f->primeiro->proximo; //2º lugar se torna 1º
            f->primeiro->proximo = aux; //1º como aux dá a mão pro 1º (anteriomente 2º lugar)
            aux->proximo = aux3; //2º lugar atual dá a mão para o 3º...
        }
    }
}


//Solução Machion
void passa_vez_info (t_fila *f) {
    int primeiro, segundo;
    if (f->tamanho > 1) {
        primeiro = f->primeiro->info;
        segundo = f->primeiro->proximo->info;
        f->primeiro->info = segundo;
        f->primeiro->proximo->info = primeiro;
    }
}

//Solução Machion
void passa_vez_ponteiro (t_fila *f) {
    s_no *primeiro, *segundo;
    if (f->tamanho > 1) {
        primeiro = f->primeiro;
        segundo = f->primeiro->proximo;
        segundo->proximo = primeiro;
        primeiro->proximo = segundo->proximo;
        f->primeiro = segundo;
    }
}
