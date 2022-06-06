#include <stdio.h>
#include "no.h"

int main(){

    int i, j;
    s_no *no1,*no2;

    printf ("digite o primeiro valor: ");
    scanf ("%d", &i);

    printf ("digite o segundo valor: ");
    scanf ("%d", &j);

    no1 = constroi_no(i);
    no2 = constroi_no(j);

    no1->proximo = no2;

    printf("endereco do primeiro no: %p\n", no1);
    printf("endereco do segundo no: %p\n", no2);


    //no1 = no2; ->  perde a referencia para no1, perde a informação
    return 0;
}