#include <time.h>
#include "pilha_vetor.h"

void teste_hanoi(){
    t_pilha p1;
    inicia_pilha (&p1);
    hanoi(5, &p1);
    hanoi(3, &p1);
    hanoi(2, &p1);
    hanoi(1, &p1);
    exibe_pilha(&p1);
    hanoi(6, &p1);
    exibe_pilha(&p1);
}

int main () {
    teste_hanoi();
    return 0;
}