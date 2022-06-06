#include "lista.h"

void constroi_lista (s_lista *l) {
    l->primeiro = NULL;
}

int esta_vazia (s_lista *l) {
    if (l->primeiro == NULL) 
        return 1;
    else
        return 0;
    //return l->primeiro == NULL;
}

int insere_inicio (int i, s_lista *l) {
    s_no * novo = constroi_no(i);
    if (novo==NULL) return FRACASSO;
    if (!esta_vazia(l)) {
        novo->proximo = l->primeiro;
    }
    l->primeiro = novo;
    return SUCESSO;
}

void mostra_lista (char *msg, s_lista *l) {
    s_no * aux;
    printf ("\n%s: ", msg);
    if (esta_vazia(l)) {
        printf ("lista vazia");
    }
    else {
        aux = l->primeiro;
        printf ("lista: ");
        while (aux != NULL) {//busca pelo final da lista
            printf ("%d ", aux->info);
            aux = aux->proximo;
        }
    }
    printf ("\n");
}

int insere_fim (int i, s_lista *l) {
    s_no * novo = constroi_no(i);
    s_no * aux;
    if (novo == NULL) return FRACASSO;
    if (esta_vazia(l)) {
        l->primeiro = novo;
    }
    else {
        aux = l->primeiro;
        while (aux->proximo != NULL) {//busca pelo último da lista
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    return SUCESSO;
}
int remove_inicio (s_lista *l) {
    int i = l->primeiro->info;
    s_no * aux = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free (aux);
    return i;
}
int remove_fim (s_lista *l){
    int i;
    s_no * aux1;
    s_no * aux2;
    if (l->primeiro->proximo == NULL) {
        i = l->primeiro->info;
        free(l->primeiro);
        l->primeiro = NULL;
    }
    else{
        aux1 = l->primeiro;
        while (aux1->proximo != NULL){
            aux2 = aux1;
            aux1 = aux1->proximo;
        }
        i = aux1->info;
        aux2->proximo = NULL;
        free (aux1);
    }
    
    return i;
}

s_lista * remove_par(s_lista *l){
    s_lista * impar;
    impar = (s_lista *) malloc (sizeof(s_lista)); //alocação da nova lista, para um espaço em memória
    constroi_lista(impar);
    int aux;
    while(!esta_vazia(l)){
        aux = remove_inicio(l); //remove todas as situações
        if(aux%2!=0){
            insere_fim(aux, impar);
        }
    }
return impar;
}


void remove_pares (s_lista *l) {
    s_no *anterior, *atual;
    //removendo do início, se houver
    //note o uso de um "super if"
    while (l->primeiro!=NULL && l->primeiro->info % 2 == 0) {
            atual = l->primeiro;
            l->primeiro = l->primeiro->proximo;
            free(atual);
        }
        if (!esta_vazia(l) && l->primeiro->proximo != NULL) {
        //tem que ter pelo menos 2 na lista
        anterior = l->primeiro;
        atual = l->primeiro->proximo;
        while (atual != NULL) {
            if (atual->info % 2 == 0) {
                anterior->proximo = atual->proximo;
                free(atual);
                atual = anterior->proximo;
            }
            else {
                anterior = atual;
                atual = atual->proximo;
            }
        }
    }
}
