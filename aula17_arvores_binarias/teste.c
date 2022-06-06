#include <time.h>
#include "arvore.h"

int main(){

    int nos, i;
    struct arvore a;
    inicializa_arvore(&a);

    srand(time(0));
    for(nos=1; nos<=9; nos++){
        i = rand()%100;
        printf("%d\n", i);
        insere(i, &a);
    }
    mostra_em_ordem(&a);
    return 0;
}
