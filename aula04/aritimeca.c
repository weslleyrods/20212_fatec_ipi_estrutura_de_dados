#include <stdio.h>

int main (){

    int v[5], i;

    for (i=0; i<5; i++){
        v[i] = i*10;
        printf ("posicao %p, valor %d\n", v+i, v[i]); //aritimetica de ponteiros
    }


    return 0;
}