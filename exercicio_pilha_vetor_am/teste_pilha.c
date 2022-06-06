#include <time.h>
#include "pilha.h"

int main(){

    t_pilha p1;
    inicia_pilha(8, &p1);
    //srand(time(0));
    push(1000, &p1);
    push(4, &p1);
    push(13, &p1);
    push(200, &p1);
    push(1500, &p1);
    
    exibe_pilha(&p1);

    t_pilha p2;
    inicia_pilha(8, &p2);
    
    push(5, &p2);
    push(4, &p2);
    push(3, &p2);
    push(2, &p2);
    push(1, &p2);
    
    exibe_pilha(&p2);

    
    // printf("Tamanho da pilha: %d", tamanho_pilha(&p1));

    printf("As pilhas sao %d\n", compara_pilhas(&p1, &p2));

    printf("Maior elemento: %d", maior_elemento(&p1));

    /*  srand(time(0));
    do{
        if (rand() %2){//valor gerado impar: empilha, se não estiver cheia    
            if (!esta_cheia(&p1)){
                push(rand()%10, &p1);
            }
        }
        else{//valor gerador par: desempilha, se não estiver vazia
            if(!esta_cheia(&p1)){
                printf ("%d foi desempilhado\n", pop(&p1));
            }
            exibe_pilha(&p1);
        }
    }while (!esta_cheia(&p1)); 
*/

    return 0;
}

