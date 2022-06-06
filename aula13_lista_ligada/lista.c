#include "lista.h"

void constroi_lista (s_lista *l) {
    l->primeiro = NULL; //um start para a construção das listas
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
    //Caso a lista só tenha um nó
    if (l->primeiro->proximo == NULL) {
        i = l->primeiro->info;
        free(l->primeiro);
        l->primeiro = NULL;
    }
    //Caso a lista tenha mais de um nó
    else{
        aux1 = l->primeiro;
        while (aux1->proximo != NULL){
            aux2 = aux1;
            aux1 = aux1->proximo;
        }
        i = aux1->info;
        aux2->proximo = NULL; //aux2 virou o último nó
        free (aux1);
    }
    return i;
}