#include "lista.h"

void constroi_lista (s_lista *l) {
    l->primeiro = NULL; //a lista nasce vazia
}

int esta_vazia (s_lista *l) {
    if (l->primeiro == NULL) 
        return 1;
    else
        return 0;
    //return l->primeiro == NULL;
}

