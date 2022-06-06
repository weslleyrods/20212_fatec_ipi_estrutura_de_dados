#include <stdio.h>
#include <stdlib.h>

void f1 (int v[], int n){}

void f2 (int *v, int n){}

int main (){

    int v1[5], v2[10]; //vetores estaticos
    int *v3 = (int *) malloc(7 * sizeof(int));  //vetor dinâmico

    printf ("Vetor v1: %p\n", v1);
    printf ("Tamanho da memoria associada a v1 = %d bytes\n", sizeof(v1));

    printf ("Vetor v2: %p\n", v2);
    printf ("Tamanho da memoria associada a v2 = %d bytes\n", sizeof(v2));

    printf ("Vetor v3: %p\n", v3);
    printf ("Tamanho da memoria associada a v3 = %d bytes\n", sizeof(v3));
   
    f1 (v1, 5);
    f2 (v1, 5);  

    f1 (v3, 7);
    f2 (v3, 7);
    return 0;
}