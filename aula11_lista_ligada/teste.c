#include <time.h>
#include "lista.h"

void teste_no(){
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
}

void teste_lista(){
    s_lista l;
    constroi_lista(&l);
    mostra_lista("Lista foi criada",&l);
    if (insere_inicio(7, &l)) 
        printf("7 inserido no inicio com sucesso\n");
    else
        printf("falha na alocacao de memoria\n");
    if(insere_inicio(3, &l))
        printf ("3 inserido  no inicio com sucesso\n");
    else 
        printf ("falha na alocacao de memoria\n");
    mostra_lista("Lista depois das insercoes de fim", &l);
    
    insere_inicio(5, &l);
    insere_inicio(4, &l);
    mostra_lista("lista depois das insercoes de inicio", &l);
    
    insere_fim(1, &l);
    insere_fim(2, &l);
    insere_fim(3, &l);
    mostra_lista("lista depois das insercoes de fim", &l);

    if(esta_vazia(&l)){
        printf("lista vaizia, não há o que remover\n");
    }
    else{
        printf ("%d foi removido do inicio\n", remove_inicio(&l));
        mostra_lista("lista depois da remocao de inicio", &l);
    }
}

int main(){
    //teste_no();
    //teste_lista();
    //no1 = no2; ->  perde a referencia para no1, perde a informação

    int num;
    s_lista l;
    constroi_lista(&l);
    srand(time(0));
    do{
        if (rand()%2){//rand = 1 => inserir
            num = rand()%10;
            if (num%2){
                insere_fim(num, &l);
            }
            else{
                insere_inicio(num, &l);
            }
        }
        else{//rand = 0 => remover
            if (rand()%2){
                remove_fim(&l);
            }
            else{
                remove_inicio(&l);
            }
        }
        mostra_lista("lista: ",&l);
    }while (!esta_vazia(&l));
    return 0;
}