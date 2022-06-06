#include <time.h>
#include "fila.h"


int main(){

    t_fila f1, f2, nova;
    inicia_fila(&f1);
    inicia_fila(&f2);
    inicia_fila(&nova);
    
    insere(1, &f1);
    insere(3, &f1);
    insere(5, &f1);
    insere(2, &f2);
    insere(4, &f2);
    insere(6, &f2);

    exibe_fila(&f1);
    exibe_fila(&f2);

    inicia_fila(&nova);

    merge_fila(&f1, &f2, &nova);
    exibe_fila(&nova);


    // srand(time(0));
    // do{
    //     if (rand() %2){//valor gerado impar: entra na fila
    //         insere(rand()%10, &f1);
    //     }
    //     else{//valor gerador par: elemento é atendido, se não estiver vazia
    //         if(!esta_vazia(&f1)){
    //             printf ("%d foi atendido\n", remove_f(&f1));
    //         }
    //         exibe_fila(&f1);
    //     }
    // }while (!esta_vazia(&f1));
    return 0;
}