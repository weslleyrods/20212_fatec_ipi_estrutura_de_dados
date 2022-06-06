#include <stdio.h>
#include <stdlib.h>

//uma estrutura vetor controlado, o tamanho dele e o número de posições ocupadas
typedef struct s {
    int *v;//ponteiro de vetor
    int capacidade, ocupacao;
} vetor_controlado;

//função que inicializa um vetor controlado, a partir do tamanho escolhido pelo usuário
void inicializa_vetor (int, vetor_controlado *);

int main () {
    vetor_controlado v1, v2;

    vetor_controlado *pvc;
    
    int aux;
    printf ("digite a capacidade para o vetor 1: ");
    scanf ("%d", &aux);
    inicializa_vetor (aux, &v1);
    printf ("inicializou v1,\n");

    printf ("digite a capacidade para o vetor 2: ");
    scanf ("%d", &aux);
    inicializa_vetor (aux, &v2);
    printf ("inicializou v2,\n");

    //alocando a estrutura que pvc vai apontar
    pvc = (vetor_controlado *) malloc (sizeof(vetor_controlado));
    //inicialização do vetor apontado por pvc
    inicializa_vetor (aux, pvc);
    printf ("inicializou pvc,\n");

    return 0;
}

//operador seta foi utilizado porque vc é um ponteiro de estrutura
//operador seta indica onde na estrutura que deve ocorrer a alteração
void inicializa_vetor (int tam, vetor_controlado *vc) {
    vc->capacidade = tam; 
    vc->ocupacao = 0;
    vc->v = (int *) malloc (tam * sizeof(int));
}