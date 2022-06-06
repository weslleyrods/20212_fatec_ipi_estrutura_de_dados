#include <time.h>
#include "pilha.h"

void teste_tamanho () {
    t_pilha p1, p2;
    inicia_pilha(8, &p1);
    inicia_pilha(8, &p2);
    printf("Tamanho da pilha antes da insercao %d\n", tamanho_pilha(&p1));

    push(10, &p1);

    printf("Tamanho da pilha antes da insercao %d", tamanho_pilha(&p1));
}

void teste_comparacao() {
    t_pilha p1, p2;
    inicia_pilha(3, &p1);
    inicia_pilha(3, &p2);

    push(10, &p1);
    push(10, &p1);
    push(10, &p1);

    push(10, &p2);
    push(10, &p2);
    push(10, &p2);

    printf("\n\nfuncao 1\n\n");

    if (compara_pilhas(&p1, &p2)) 
        printf("As listas sao iguais");
    else
        printf("As listas sao diferentes");
    
    printf("\n\nfuncao 2\n\n");

    if (compara_pilhas_dois(&p1, &p2)) 
        printf("As listas sao iguais");
    else
        printf("As listas sao diferentes");
}

void teste_maior_elemento () {
    t_pilha p;
    inicia_pilha(5, &p);
    for(int i = 0; i < p.capacidade; i++)
        push(rand()%100, &p);
    
    exibe_pilha(&p);
    printf("\nfuncao 1\n");
    printf("O maior elemento da pilha eh: %d\n", maior_elemento_pilha(&p));
    
    printf("\nfuncao 2\n");
    printf("O maior elemento da pilha eh: %d\n", maior_elemento_pilha_dois(&p));
}

int main(){
    srand(time(0));
    
    // teste_tamanho();
    // teste_comparacao();
    teste_maior_elemento();

    // do{
    //     if (rand() %2){//valor gerado impar: empilha, se não estiver cheia    
    //         if (!esta_cheia(&p1)){
    //             push(rand()%10, &p1);
    //         }
    //     }
    //     else{//valor gerador par: desempilha, se não estiver vazia
    //         if(!esta_cheia(&p1)){
    //             printf ("%d foi desempilhado\n", pop(&p1));
    //         }
    //         exibe_pilha(&p1);
    //     }
    // }while (!esta_cheia(&p1));
    return 0;
}