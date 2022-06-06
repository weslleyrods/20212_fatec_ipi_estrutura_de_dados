#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void bubble (int *, int);
void bubble_invertido (int *, int);
void gera_vetor (int*, int); 
void mostra_vetor (int*, int, const char *);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
int v, n;
char nome[9];

    printf ("Digite o tamanho do vetor: ");
    scanf ("%d", &n);
    v  = (int*) malloc (n*sizeof(int));
    srand(time(0));
    
    gera_vetor(v, n);
    mostra_vetor (v, n, "vetor gerado");
    
    bubble (v, n);
    mostra_vetor (v, n, "vetor ordenado pelo Bubble original");
    
    bubble_invertido (v, n);
    mostra_vetor (v, n, "vetor ordenado decrescente pelo Bubble inverso");

    return 0;
}

void gera_vetor (int *v, int n){
    int i;
    for(i=0; i< n; i++){
            v[i] = rand()%100; 
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
        //BUBBLE ORIGINAL
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

void bubble_invertido (int *v, int n){
    int i, j, aux;
        //número de vezes que irá passar pelo vetor
        for(i=1; i<n; i++){ //se n = 8, irá ter total de 7 passadas
            for(j=0; j<n-1;j++){              
                if (v[j]<v[j+1]){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}
