#include "lista.h"

//verificar se um número está ou não em uma lista
int busca_numero (int n, s_lista *l) {
    s_no * aux = l->primeiro;
    while (aux != NULL) {
        if (n == aux->info)
            return SUCESSO;
        aux = aux->proximo;
    }
    return FRACASSO;
}

//verificar se um número está ou não em uma lista, devolvendo a sua primeira ocorrencia (POSIÇÃO) ou 0 em caso negativo
int busca_posicao_numero (int n, s_lista *l) {
    s_no * aux = l->primeiro;
    int posicao = 1;
    while (aux != NULL) {
        if (n == aux->info)
            return posicao;
        aux = aux->proximo;
        posicao++;
    }
    return 0;
}

//verificar quantas vezes um número aparece numa lista
int busca_vezes_numero (int n, s_lista * l) {
    int v = 0;
    s_no * aux = l->primeiro;
    while (aux != NULL){
        if (n == aux->info){
            v++;
        }
        aux = aux->proximo;
    }
    return v;
}


//inserir um número em uma lista em uma determinada posição
int insere_numero_posicao_lista (int numero, int posicao, s_lista * l) {
    int cont;
    s_no * aux;
    s_no * novo;
    if (posicao <= 1) return insere_inicio(numero, l);
    novo = constroi_no(numero);
    if (novo != NULL) {
        aux = l->primeiro;
        cont = 1;
        while (cont < posicao-1 && aux->proximo) {  
            cont++;
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        return SUCESSO;
    }
    return FRACASSO;
}

//remover um número de uma determinada posiçao
int remove_numero_posicao_lista (int posicao, s_lista * l){
    int cont, i;
    s_no *aux1, *aux2;
    if (posicao <= 1 || l->primeiro->proximo == NULL){
        return remove_inicio(l);
    }
    else{
        aux1 = l->primeiro;
        cont = 1;
        while (cont < posicao-1 && aux1->proximo) {
            cont++;
            aux1 = aux1->proximo;
        }
        if (aux1->proximo == NULL) { //batemos no final da lista, vamos remover o último
            return remove_fim(l);
        }
        i = aux1->proximo->info;
        aux2 = aux1->proximo;
        aux1->proximo = aux1->proximo->proximo;
        free (aux2);
        return i;
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

//opção 2
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

int main () {
    // int pos, quantidade;
    s_lista * nova;
    s_lista l1, l2, l3;
    constroi_lista(&l1);
    insere_inicio(2, &l1);
    insere_inicio(4, &l1);
    insere_inicio(6, &l1);
    insere_inicio(8, &l1);
    constroi_lista(&l2);
    insere_inicio(3, &l2);
    insere_inicio(5, &l2);
    mostra_lista("lista 1", &l1);
    mostra_lista("lista 2", &l2);

    nova = mesclada1 (&l1, &l2);
    mostra_lista("lista nova", nova);

    insere_inicio(2, &l1);
    insere_inicio(4, &l1);
    insere_inicio(6, &l1);
    insere_inicio(8, &l1);
    insere_inicio(3, &l2);
    insere_inicio(5, &l2);
    constroi_lista(&l3);
    mesclada2(&l1, &l2, &l3);
    mostra_lista ("lista 3", &l3);

    // if (busca_numero(2, &l)) printf ("2 esta na lista\n");
    // else printf ("2 nao esta na lista\n");
    
    // if (busca_numero(12, &l)) printf ("12 esta na lista\n");
    // else printf ("12 nao esta na lista\n");

    // pos = busca_posicao_numero(2, &l);
    // if (pos) printf ("2 esta na lista, na posicao %d\n", pos);
    // else printf ("2 nao esta na lista\n");
    
    // pos = busca_numero(12, &l);
    // if (pos) printf ("12 esta na lista, na posicao %d\n", pos);
    // else printf ("12 nao esta na lista\n");

    // quantidade = busca_vezes_numero(4, &l);
    // if (quantidade) printf ("4 aparece na lista %d vezes\n", quantidade);
    // else printf ("4 nao esta na lista\n");
    
    // quantidade = busca_vezes_numero(12, &l);
    // if (quantidade) printf ("12 aparece na lista %d vezes\n", quantidade);
    // else printf ("12 nao esta na lista\n");
    
    // mostra_lista("", &l);

    // if(insere_numero_posicao_lista (10, 0, &l)) {
    //     mostra_lista ("10 na posicao 0", &l);
    // }
    // else {
    //     printf ("falha ao inserir 10 na posicao 0\n");
    // }
    // if(insere_numero_posicao_lista (20, 3, &l)) {
    //     mostra_lista ("20 na posicao 3", &l);
    // }
    // else {
    //     printf ("falha ao inserir 20 na posicao 3\n");
    // }
    // if(insere_numero_posicao_lista (30, 30, &l)) {
    //     mostra_lista ("30 na posicao 30", &l);
    // }
    // else {
    //     printf ("falha ao inserir 30 na posicao 30\n");
    // }

    // printf ("%d saiu da posicao 0\n", remove_numero_posicao_lista (0, &l));
    // mostra_lista("depois da remocao da posicao 0", &l);

    // printf ("%d saiu da posicao 4\n", remove_numero_posicao_lista (4, &l));
    // mostra_lista("depois da remocao da posicao 4", &l);

    // printf ("%d saiu da posicao 20\n", remove_numero_posicao_lista (20, &l));
    // mostra_lista("depois da remocao da posicao 20", &l);

    return 0;
}

//Remover todas as ocorrências de um número em uma lista
//Inserir valores numa lista respeitando a ordem dos valores
//Mesclar 2 listas em uma uma, respeitando a ordem entre os elementos
//Dividir uma lista em 2
