#include "lista.h"

// inserir um número em uma lista em uma determinada posição.
int insere_posicao (int n, int p, s_lista *l){
    s_no * aux;
    s_no * novo;
    int cont = 1;
    
    if (p <= 1) return insere_inicio(n, l);
    novo = constroi_no(n);
    aux = l->primeiro;
    if (novo != NULL) {
        while(cont < p-1 && aux->proximo){
            aux = aux->proximo;
            cont++;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        return SUCESSO;
    }
    return FRACASSO;
}

// remover um número de uma determinada posiçao

int remove_numero_posicao(int p, s_lista *l){
    int cont = 1, i;
    s_no * aux, * aux2;

    //Caso a lista tenha apenas um elemento
    aux = l->primeiro;
    if(p <= 1 || aux->proximo == NULL){ //Identicar se a lista tem apena sum elemento
        return remove_inicio(l);
    }
    else{
        while(cont < p-1 && aux->proximo->proximo) {
            aux = aux->proximo;
            cont++;
        }
        /* if (aux->proximo == NULL){//verifica se a posicao a ser removida é a ultima
            return remove_fim(l);
        } */
        i = aux->proximo->info;//valor removido
        aux2 = aux->proximo;
        aux->proximo = aux2->proximo;
        free(aux2);
        return i;
    }  
}

int main (void) {

    s_lista lista;
    constroi_lista(&lista);

    insere_fim(10, &lista);
    insere_fim(5, &lista);
    insere_fim(4, &lista);
    insere_fim(6, &lista);
    insere_fim(8, &lista);
    
    mostra_lista("Lista atual", &lista);

    insere_posicao(7, 3, &lista);

    mostra_lista("Depois da inserção do 7 na posicao 3", &lista);

    remove_numero_posicao(3, &lista);
    mostra_lista("Depois da remocao do 7", &lista);

    remove_numero_posicao(7, &lista);
    mostra_lista("Depois da remocao da 7° posicao", &lista);

    return 0;
}