#include <stdio.h>
#include <stdlib.h>

void vfloat (float);

void preenchev (int, float *);

float calcmedia (int, float *);

int verificaMedia(float *, int, float );

int main(){

    float *v;
    int i, tam;
    printf ("Digite o tamanho do vetor: ");
    scanf ("%d", &tam);
    v  = (float*) malloc (tam*sizeof(float));

    printf ("Digite os valores do vetor: ");
    preenchev (tam, v);
    for(i=0; i<tam; i++){
        printf ("%.2f ", v[i]);
    }

    float media = calcmedia(tam, v);
    printf ("A media dos valores do vetor e: %.2f\n", media);

    int ocorrencia = verificaMedia(v, tam, media);
    printf ("Os numeros do vetor maior que a media e: %d\n", ocorrencia);
    
    return 0;
}

void preenchev (int tam, float * v){
    int i;
    for(i=0; i< tam; i++){
    scanf ("%f", &v[i]);   
    }
}

float calcmedia (int tam, float *v){
    int i; 
    float soma = 0.0;
    for (i=0; i<tam; i++){
        soma = soma + v[i];   
    }
        return soma/tam;
}

int verificaMedia (float *v, int tam, float media){
    int i, maior_qa_media = 0;
    for (i=0; i<tam; i++){
        if( v[i] > media)
        maior_qa_media++;   
    }
return maior_qa_media;
}