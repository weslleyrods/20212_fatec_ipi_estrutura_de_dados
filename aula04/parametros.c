#include <stdio.h>

void f1(int a) { //passagem de parametro por valor -> copia temporaria
    a++;
    }

    void f2 (int *a) { //passagem de parametro por referencia -> valor original
        (*a)++; //os parenteses fazem que o ponteiro tenha prioridade de ordem de execução
    }

    int main (){
        int m=10, n=10;
        f1(m);
        printf ("m: %d\n", m);
        f2(&n);
        printf ("n: %d\n", n);
    }