#include <stdio.h>

int main (){
    int i; //inteiro
    int *pi; //ponteiro de inteiro
    float f; //float
    float *pf; //ponteiro de float

    float **ppf; //para ponteiro de ponteiro float

    printf ("tamanho do inteiro = %d\n", sizeof(int));
    printf ("tamanho do ponteiro inteiro = %d\n", sizeof(int *));
    printf ("tamanho do float = %d\n", sizeof(f));
    printf ("tamanho do ponteiro float = %d\n", sizeof(pf));


    i = 10;
    pi = &i; //& = operador referencia (endereço  em memoria)

    f = 3.75;
    pf = &f; //& = operador referencia (endereço  em memoria)

    printf ("i = %d\npi = %p\n", i, pi);
    printf ("f = %f\npf = %p\n", f, pf);


    printf ("onde esta o pi: %p\n", &pi); //o endereço do ponteiro de um poteiro pode ser apresentado diretamente

    ppf = &pf; //ou pedir para ser apontado
    printf ("onde esta o pf: %p\n", ppf);


    *pi = 20; //* operador derreferencia
    printf ("novo valor de i = %d\n", i);

    return 0;
}