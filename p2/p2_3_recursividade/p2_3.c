#include <stdio.h>
#include <stdlib.h>
//ORIGINAL
int maximo (int v[], int n) {
    int i, m = v[0];
    for (i=1; i<n; i++)
    if (v[i] > m)
    m = v[i];
    return m;
}

//RECURSIVA
int maximo_rec(int v[], int tam, int aux){
        if(tam == 0)
            return v[aux];  
        else{
            if(v[tam-1] > v[aux])
                return maximo_rec(v, tam-1, tam-1);
                
            else
                return maximo_rec(v, tam-1, aux); //cai no else enquanto o 1º indice do vetor for o maior de todos
    }
}

void exibe_vetor(int v[], int tam){
    int i;
    printf("\n");
    for (i = 0; i < tam; i++) {  
        printf ("%d ", v[i]);
    }
    
}
int main(){

    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    int i, v[tam];

    for (i = 0; i < tam; i++) {   //Para preencher o vetor
    printf ("Digite um numero: ");
    scanf ("%d", &v[i]);
    }
    printf("vetor antes da funcao\n\n");
    exibe_vetor(v, tam);
    printf("\n\nO maior elemento pela funcao original: %d\n", maximo(v, tam));
    printf("\n\nO maior elemento buscado pela recursidade: %d\n", maximo_rec(v, tam, 0)); //v[0] funciona como um start para percorrer o vetor
    return 0;
}
