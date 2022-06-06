#include <time.h>
#include "pilha.h"


int main(){

    t_pilha p1;
    inicia_pilha(&p1);
    exibe_pilha(&p1);
    srand(time(0));
    do{
        if (rand() %2){//valor gerado impar: empilha, se não estiver cheia    
            push(rand()%10, &p1);
        }
        else{//valor gerador par: desempilha, se não estiver vazia
            if(!esta_cheia(&p1)){
                printf ("%d foi desempilhado\n", pop(&p1));
            }
            exibe_pilha(&p1);
        }
    }while (!esta_cheia(&p1));
    return 0;
}