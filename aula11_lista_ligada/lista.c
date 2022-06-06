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

int insere_inicio(int i, s_lista*l){
    s_no * novo = constroi_no(i);
    if (novo==NULL) return FRACASSO;
    if (novo != NULL){
        if (!esta_vazia(l)){
            novo->proximo = l->primeiro;
        }
        l->primeiro = novo;
    } 
    return SUCESSO; //se o novo for != de NULL
}

void mostra_lista (char * msg, s_lista* l){
    s_no * aux; //para percorrer pela lista
    printf ("\n%s\n", msg);
    if (esta_vazia(l)){
        printf ("lista vazia");
        }
    else{
        aux = l->primeiro; 
        printf ("lista: "); 
        while (aux !=NULL){ //busca pelo final da lista, até cair no vazio
            printf("%d", aux->info);
            aux = aux ->proximo;
        }
    }
    printf("\n");
}

int insere_fim(int i, s_lista *l){
    s_no * novo = constroi_no(i);
    s_no * aux;
    if (novo == NULL) return FRACASSO;
    if (esta_vazia(l)){
        l-> primeiro = novo;
    }
    else{
        aux = l->primeiro; //aux recebe uma cópia do endereço do primeiro elemento
        while (aux->proximo != NULL){ //busca pelo ultimo da lista
            aux = aux->proximo; //aux avança pela lista fazendo uma cópia do endereço dos elemento seguintes
        } 
            aux->proximo = novo; //quando aux encontrar o final da lista, adiciona o novo nó
    }
    return SUCESSO;
}

int remove_inicio (s_lista *l){
    int i = l->primeiro->info;
    s_no * aux = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free (aux);
    return i;
}

