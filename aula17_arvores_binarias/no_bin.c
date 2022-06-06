#include "no_bin.h"

struct no_bin * cria_no_bin(int i){
    struct no_bin * no;
    no = (struct no_bin *) malloc (sizeof(struct no_bin));
    if (no){
        no->info = i;
        no->dir = NULL;
        no->esq = NULL;
    }
    return no;
}

