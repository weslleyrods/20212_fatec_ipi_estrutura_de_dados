#include <time.h>
#include "fila.h"

void teste_passa_vez(){
t_fila f1;
    inicia_fila(&f1);
    insere(3, &f1);
    insere(2, &f1);
    insere(4, &f1);
    exibe_fila(&f1);
    //passa_vez_info(&f1);
    passa_vez(&f1);
    exibe_fila(&f1);
}
int main(){
    teste_passa_vez();
    return 0;
}