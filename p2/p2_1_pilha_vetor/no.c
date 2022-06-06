#include "no.h"

s_no * constroi_no (int i) {
    s_no * novo = (s_no *) malloc (sizeof(s_no));
    if (novo != NULL) {
        novo->info = i;
        novo->proximo = NULL;
    }
    return novo;
}

