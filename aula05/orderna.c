
#include <stdio.h>
#include <stdlib.h> //para fazer uso do malloc
#include <time.h>

void gera_getor (int*, int); //
void bubble (int*, int); //executa a ordenação bubble
void mostra_vetor (int*, int, const char *);

int main(){
    int *v, n;
    unsigned long int ini, fim;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v  = (int*) malloc (n*sizeof(int));
    srand(time(0));//srand é o inicializador do rand. O time(0) é um funcao que lê o tempo da máquina desde 1970
    //aqui foi utlizada como semente de geração, para que o inicializador nunca comece do mesmo lugar
    //evitando que a sequencia inteira não se repita
    gera_vetor(v, n);
    mostra_vetor (v, n, "vetor gerado");
    ini = time(0);
    bubble (v, n);
    fim = time(0);
    mostra_vetor (v, n, "vetor ordenado");
    printf("\nordenacao do vetor de tamanho %d demorou %u s\n", n, fim-ini);

    return 0;
}

void gera_vetor (int *v, int n){
    int i;
    for(i=0; i< n; i++){
            v[i] = rand()%100; //remover %100 caso queira valores maiores
            //%100 para pegar qlqr valor e fazer resto 100, ou seja, de 0 a 99
    }
    }
void mostra_vetor (int *v, int n, const char * msg){
    int i;
    printf("\n%s\n", msg);
    for(i=0; i< n; i++){
        printf ("%d ", v[i]);           
    }
        printf ("\n"); 
    }
void bubble (int *v, int n){
    int i, j, aux;
    for(i=1; i<n; i++){
        for(j=0;j<n-i;j++){
            if (v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

