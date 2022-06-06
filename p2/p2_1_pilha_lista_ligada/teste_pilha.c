#include <time.h>
#include "pilha_lista.h"

void testa_hanoi(){
    t_pilha p1;
    inicia_pilha(&p1);
    push(1, &p1);
    push(10, &p1);
    push(5, &p1);
    exibe_pilha(&p1);
    
    hanoi(6,&p1);
    exibe_pilha(&p1);

    printf("Solucao da Machion ");
    push_hanoi(4, &p1);
    exibe_pilha(&p1);
}

int main(){
    testa_hanoi();
    return 0;
}