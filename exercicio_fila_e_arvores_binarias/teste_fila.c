#include <time.h>
#include "fila.h"

void testa_tamanho(){
    t_fila f1;
    inicia_fila(&f1);
    exibe_fila(&f1);

    insere(1, &f1);
    insere(2, &f1);
    insere(3, &f1);

    exibe_fila(&f1);
    printf("tamanho da fila = %d\n ", tamanho_fila(&f1));
}

void testa_compara(){
    t_fila f1, f2;
    inicia_fila(&f1);
    inicia_fila(&f2);
    exibe_fila(&f1);
    exibe_fila(&f2);

    insere(2, &f1);
    insere(3, &f1);
    insere(4, &f1);

    insere(7, &f2);
    insere(9, &f2);
    insere(8, &f2);

    exibe_fila(&f1);
    exibe_fila(&f2);

    printf("As filas sao: %s\n", compara_fila(&f1,&f2)?"Iguais":"Diferentes");
}
void testa_merge(){
    t_fila f1, f2, f3;
    inicia_fila(&f1);
    inicia_fila(&f2);
    inicia_fila(&f3);

    exibe_fila(&f1);
    exibe_fila(&f2);

    insere(1, &f1);
    insere(3, &f1);
    insere(5, &f1);

    insere(2, &f2);
    insere(4, &f2);
    insere(6, &f2);
    
    merge_fila(&f1, &f2,&f3);
    exibe_fila(&f3);

}

void gera_sequencia(){
    srand(time(0));
    for (int i = 0; i < 15; i++)
        printf("%d ", rand() % 20);  
        printf("\n");
}

int main(){
    testa_tamanho();
    testa_compara();
    testa_merge();
    gera_sequencia();

    return 0;
}