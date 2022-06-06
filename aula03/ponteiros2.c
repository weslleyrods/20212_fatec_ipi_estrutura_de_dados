#include <stdio.h>
#include <stdlib.h> //para utilizar as funções de alocação de memoria

int main (){

    int *v;
    int n;

    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &n);

    v = (int *) malloc(n * sizeof(int)); //notem o casting

    printf ("tamanho de v = %d\n", sizeof(v));
    printf ("v = %p", v);

    return 0;
}