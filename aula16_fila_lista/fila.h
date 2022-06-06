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



//Exercicios

//1. Dadas 2 filas, fazer o merge entre elas
/* void merge_f(t_fila *, t_fila *);

void merge_f(t_fila *f1, t_fila *f2, t_fila*nova){

    while(!esta_vazia(f1) && !esta_vazia(f2)){
        insere(&f1, nova);
        insere(&f2, nova);
    }
    


} */

/* //opção 2
void mesclada2 (s_lista * l1, s_lista * l2, s_lista * nova) {
    while (!esta_vazia(l1) && !esta_vazia(l2)) {
        insere_inicio(remove_inicio(l1), nova);
        insere_inicio(remove_inicio(l2), nova);
    }
    while (!esta_vazia(l1)) {
        insere_inicio(remove_inicio(l1), nova);
    }
    while (!esta_vazia(l2)) {
        insere_inicio(remove_inicio(l2), nova);
    }
} 


//Mesclar 2 listas em uma (lembre-se que elas podem ter tamanhos diferentes)

 //opção 1
s_lista * mesclada1 (s_lista * l1, s_lista * l2) {
    s_lista * nova;
    nova = (s_lista *) malloc (sizeof(s_lista)); 
    constroi_lista(nova);
    while (!esta_vazia(l1) && !esta_vazia(l2)) {
        insere_inicio(remove_inicio(l1), nova);
        insere_inicio(remove_inicio(l2), nova);
    }
    while (!esta_vazia(l1)) {
        insere_inicio(remove_inicio(l1), nova);
    }
    while (!esta_vazia(l2)) {
        insere_inicio(remove_inicio(l2), nova);
    }
    return nova;
}
*/

