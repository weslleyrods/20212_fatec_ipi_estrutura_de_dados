
#include <stdio.h>
#include <stdlib.h> //para fazer uso do malloc
#include <time.h>

void gera_vetor (int*, int); //
void bubble (int*, int); //executa a ordenação bubble
void insertion (int*, int);
void selection (int *, int);
void mostra_vetor (int*, int, const char *);

int main(){
    int *v, n, pass = 1, valor = 0;
    int vn[] = {100000, 200000, 500000, 1000000};
    unsigned long int ini, fim;
    srand(time(0));
    //printf("Digite o tamanho do vetor: ");
    //scanf("%d", &n);

    while (valor < 4) {
        n = vn[valor];
        v = (int*) malloc (n*sizeof(int));
        pass = 1;
        while (pass <= 3) {    
            // Bubble
            gera_vetor(v, n);
            ini = time(0);
            bubble (v, n);
            fim = time(0);
            printf("\nBUBBLE passada %d: ordenacao do vetor de tamanho %d demorou %u s\n", pass, n, fim-ini);
            
            // Insertion
            gera_vetor(v, n);
            ini = time(0);
            insertion (v, n);
            fim = time(0);
            printf("\nINSERT passada %d: ordenacao do vetor de tamanho %d demorou %u s\n", pass, n, fim-ini);

            // Selection
            gera_vetor(v, n);
            ini = time(0);
            selection(v, n);
            fim = time(0);
            printf("\nSELECTION passada %d: ordenacao do vetor de tamanho %d demorou %u s\n", pass, n, fim-ini);

            pass++;
        }
        valor++;
    }
    
    return 0;
}

void gera_vetor (int *v, int n){
    int i;
    for(i=0; i< n; i++){
            v[i] = rand()*rand(); //remover %100 caso queira valores maiores
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

void insertion (int *v, int n){
    int i, j, aux;
        for (i = 1; i < n; i++){
            //move as "cartas" maiores para frente
            aux = v[i];
            for(j = i; (j > 0) && (aux < v[j-1]); j--)
                v[j] = v [j-1]; //faz a troca p/ frente, caso o valor seja maior
            v[j] = aux; 
    }              
}


// Outra versão de selection
/* void selection (int * v, int n) {
    int i, j, aux, menor;
    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) menor = j;
        }
        aux = v[i]; v[i] = v[menor]; v[menor] = aux;
    }
} */

void selection(int *v, int n){ //Esse é o select e é o mais rápido que o marcado
int i, j, min, aux;
    for (i = 0; i < (n - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < n; j++) {
    /* Caso tenha algum numero menor ele faz a troca do minimo*/
    if (v[j] < v[min]) {
    min = j;
    }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
    aux = v[i];
    v[i] = v[min];
    v[min] = aux;
    }
    }
}