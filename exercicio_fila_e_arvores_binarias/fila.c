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

//1 - Devolver o tamanho da fila
int tamanho_fila(t_fila *f){
    return f->tamanho;
}

//2 - Verificar se 2 filas são iguais
int compara_fila(t_fila *f1, t_fila *f2){
    if (tamanho_fila(f1) != tamanho_fila(f2)) return 0;
    s_no * aux1, * aux2;
    aux1 = f1->primeiro;
    aux2 = f2->primeiro;
    
    while (aux1 && aux1->info == aux2->info){
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }
    return !aux1; //caso as filas sejam diferente, nega-se aux1 porque ele ainda terá valor
                //consequentemente o tornando false
}

//3 - Receber duas filas e intercalar seus elementos em uma única (as filas de entrada se esvaziam)
void merge_fila(t_fila *f1, t_fila *f2, t_fila *nova){
    while(!esta_vazia(f1) && !esta_vazia(f2)){   
        insere(remove_f(f1), nova);   
        insere(remove_f(f2), nova);
        }
    while (!esta_vazia(f1)) {
        insere(remove_f(f1), nova);
    }
    while (!esta_vazia(f2)) {
        insere(remove_f(f2), nova);
    }
}


