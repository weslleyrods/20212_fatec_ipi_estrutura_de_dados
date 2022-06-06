#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void gera_vetor (int*, int, int);
void mostra_vetor (int*, int, const char *);
int busca_simples (int, int *, int, int *);

int main(){

    setlocale(LC_ALL, "Portuguese");

    int *v, n, inter, elemen, ocorrencia;
    printf ("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v  = (int*) malloc (n*sizeof(int));
    srand(time(0));
    printf ("Digite o intervalo do vetor: ");
    scanf("%d", &inter);
    gera_vetor(v, n, inter);
    mostra_vetor (v, n, "vetor gerado");
    printf ("\nDigite o elemento para a busca: ");
    scanf("%d", &elemen);

    ocorrencia = 0;
    busca_simples(elemen, v, n, &ocorrencia);
    if (ocorrencia > 0 ){
        printf("Foram encontradas repeticoes\n", ocorrencia);
    }
    else {
        printf("Nenhuma repeticaoo foi encontrada\n", ocorrencia);
    }

    return 0;
}

void gera_vetor (int *v, int n, int inter){
    int i;
    for(i=0; i< n; i++){
            v[i] = rand()%inter; 
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

int busca_simples (int elemen, int *v, int n, int * ocorrencia){  
    int j;
        for (j=0; j<n; j++){
            if(v[j] == elemen){
            (*ocorrencia)++;
            }
    }
}