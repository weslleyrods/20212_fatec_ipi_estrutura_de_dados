#include <time.h>
#include "lista.h"


void teste_lista_remove_par() {
    s_lista l;
    constroi_lista(&l);
    mostra_lista("lista foi criada", &l);

    insere_inicio (6, &l);
    insere_inicio (7, &l);
    insere_inicio (4, &l);
    insere_inicio (2, &l);
    insere_inicio (3, &l);
    insere_inicio (5, &l);
    mostra_lista ("lista depois das insercoes\n", &l);

    s_lista * impar = remove_par(&l);
    //remove_pares(&l);

    //mostra_lista ("lista sem os pares", &l);   
    mostra_lista ("lista sem os pares da Machion", impar);   
}

int main () {
    teste_lista_remove_par();
    return 0;
}