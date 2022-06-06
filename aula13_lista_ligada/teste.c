#include <time.h>
#include "lista.h"

void teste_no() {
    int i, j;
    s_no *no1, *no2;

    printf ("digite o primeiro valor: ");
    scanf ("%d", &i);
    printf ("digite o segundo valor: ");
    scanf ("%d", &j);

    no1 = constroi_no(i);
    no2 = constroi_no(j);

    no1->proximo = no2;
    printf ("endereco do primeiro no: %p\n", no1);
    printf ("endereco do segundo no: %p\n", no2);
    printf ("Valor do segundo %d", no1->proximo->info);
    //no1 = no2; -> perde a referência para no1, perde a informação
}

void teste_lista() {
    s_lista l;
    constroi_lista(&l);
    mostra_lista("lista foi criada", &l);
    if (insere_inicio(7, &l)) 
        printf ("7 inserido no inicio com sucesso\n");
    else 
        printf ("falha na alocacao de memoria\n");
    if (insere_inicio(3, &l))
        printf ("3 inserido no inicio com sucesso\n");
    else 
        printf ("falha na alocacao de memoria\n");

    insere_inicio (5, &l);
    insere_inicio (4, &l);
    mostra_lista ("lista depois das insercoes de inicio", &l);

    insere_fim (1, &l);
    insere_fim (2, &l);
    insere_fim (3, &l);
    mostra_lista ("lista depois das insercoes de fim", &l);

    if (esta_vazia(&l)) {
        printf("lista vazia, não há o que remover\n");
    }
    else {
        printf ("%d foi removido do inicio\n", remove_inicio(&l));
        mostra_lista ("lista depois da remocao de inicio", &l);
    }

    if (esta_vazia(&l)) {
        printf("lista vazia, não há o que remover\n");
    }
    else {
        printf ("%d foi removido do fim\n", remove_fim(&l));
        mostra_lista ("lista depois da remocao de fim", &l);
    }
}

void teste_lista_randomico () {
    int num;
        s_lista l;
        constroi_lista(&l);

        insere_inicio(6, &l);
        insere_inicio(9, &l);
        srand(time(0));
        do {
            if (rand()%2) {//rand = 1 => inserir
                num = rand() % 10;
                if (num%2) { // numero impar
                    insere_fim(num, &l);
                }
                else {
                    insere_inicio(num, &l);
                }
            }
            else {//rand = 0 => remover
                if (!esta_vazia(&l)){
                    if (rand()%2) {
                        remove_fim(&l);
                    }
                    else {
                        remove_inicio(&l);
                    }
                }
            }
            mostra_lista("", &l);
        } while (!esta_vazia(&l));
}

int main () {
    // teste_no();
    // teste_lista();
    teste_lista_randomico();

    return 0;
}