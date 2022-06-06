
#include <stdio.h>
#include <stdlib.h> //para fazer uso do malloc
#include <time.h>

void gera_getor (int*, int); //
void bubble (int*, int); //executa a ordenação bubble
void mostra_vetor (int*, int, const char *);
//Uma função que busca um inteiro i num vetor v, de tamanho n
//retorno é a posição da primeira ocorrência de i ou -1, se o elemento não existir
//o último parâmetro refere-se ao número de comparações executadas
                //elemento que irá buscar, vetor v, de tamanho n, comparacoes
int busca_simples (int, int *, int, int*, int*);
//uma função que busca um inteiro i num vetor v, de tamanho n
//retorno da função é a uma posição em que o elemento aparece ou -1, sele ele não estiver
//vamos utilizar o Algoritmo da busca binária
//vamos contar o número de comparações 
int busca_binaria (int, int *, int, int*, int*);

int main(){
    int *v, n, x, posicao, compara, ocorrencia;
    unsigned long int ini, fim;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v  = (int*) malloc (n*sizeof(int));
    srand(time(0));//srand é o inicializador do rand. O time(0) é um funcao que lê o tempo da máquina desde 1970
    //aqui foi utlizada como semente de geração, para que o inicializador nunca comece do mesmo lugar
    //evitando que a sequencia inteira não se repita
    gera_vetor(v, n);
    mostra_vetor (v, n, "vetor gerado");
    printf ("digite um valor para busca ");
    scanf("%d", &x);
    printf("\nBusca Simples:\n");
    compara = 0;
    ocorrencia = 0;
    busca_simples(x, v, n, &compara, &ocorrencia);
    if (ocorrencia > 0 ){
    printf("%d ocorrencias\n", ocorrencia);
    }
    else {
    printf("Sem ocorrencias\n", ocorrencia);
    }
    
    ini = time(0);
    bubble (v, n);
    fim = time(0);
    mostra_vetor (v, n, "vetor ordenado");
    printf("\nordenacao do vetor de tamanho %d demorou %u s\n", n, fim-ini);

    printf("\nBusca Binaria:\n");
    compara = 0;
    ocorrencia = 0;
    busca_binaria(x, v, n, &compara, &ocorrencia);
    printf("%d ocorrencias\n", ocorrencia);
}

void gera_vetor (int *v, int n){
    int i;
    for(i=0; i< n; i++){
            v[i] = rand()%10; //remover %100 caso queira valores maiores
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

int busca_simples (int i, int *v, int n, int * comparacoes, int * ocorrencia){  
    int j, c;
        for (j=0; j<n; j++){
            if(v[j] == i){
            (*ocorrencia)++;
        }
    }
}

int busca_binaria (int i, int * v, int n, int * comparacoes, int * ocorrencia) {
    int inicio = 0, fim = n - 1, meio;
    // condicao do laco fim < inicio
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        if (i == v[meio]) {
            (*ocorrencia)++;
            int aux = meio;
            if (v[aux + 1] == v[meio]){
                aux++;    
                while (v[aux] == v[meio]){
                    (*ocorrencia)++;
                    aux++;
                }
            }
            aux = meio;
            if (v[aux - 1] == v[meio]) {
                aux--;
                while (v[aux] == v[meio]){
                    (*ocorrencia)++;
                    aux--;
                }
            }
            return;
        }
        if (i > v[meio])
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
}



