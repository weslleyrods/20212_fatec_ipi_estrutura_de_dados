#include <time.h>
#include "pilha.h"

void testa_tamanho() {
    t_pilha p;
    inicia_pilha(&p);
    push(10, &p);
    push(3, &p);
    push(5, &p);

    exibe_pilha(&p);
    
    printf("O tamanho da pilha %d\n", tamanho_pilha(&p));
}

void testa_compara(){
    t_pilha p1, p2;
    inicia_pilha(&p1);
    inicia_pilha(&p2);

    push(10, &p1);
    push(2, &p1);
    push(5, &p1);

    push(10, &p2);
    push(3, &p2);
    push(5, &p2);

    exibe_pilha(&p1);
    exibe_pilha(&p2);
    
    // compara_pilha(&p1, &p2);

    if (compara_pilha(&p1, &p2))
        printf("iguais");
    else 
        printf("diferentes");
}

void testa_maior(){
    t_pilha p;
    inicia_pilha(&p);
    push(60, &p);
    push(70, &p);
    push(85, &p);

    exibe_pilha(&p);
    
    printf("O maior da pilha:  %d\n", maior_pilha(&p));
}

int main(){
    
    // t_pilha p1;
    // inicia_pilha(&p1);
    // exibe_pilha(&p1);
    // testa_tamanho();
    //testa_compara();
    testa_maior();

    
    // srand(time(0));
    // do{
    //     if (rand() %2){//valor gerado impar: empilha, se não estiver cheia    
    //         push(rand()%10, &p1);
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