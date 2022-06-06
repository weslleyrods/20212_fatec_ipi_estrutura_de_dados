#include <stdio.h>

int main (){

    int a = 10;
    int *p;

    p = &a; //p recebe a referencia de a

    *p = 20; //o conteudo apontado por p recebe 20

    printf ("a = %d\n", a);

    return 0;
}