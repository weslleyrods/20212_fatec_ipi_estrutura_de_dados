#include <stdio.h>
#include <stdlib.h>

struct s1 {
    char c;
    float f;
    int i;

};
struct s2 {
    char c;
    int i;
    int v[10];

};
struct s3 {
    char c1;
    char c2;
};
struct s4 {
    int n;
    int *v;
};


int main (){
    struct s1 s;
    struct s2 t;
    struct s3 u;
    struct s4 x;

    int n;

    struct s1*ps1;
    struct s2*ps2;

    printf ("tamanho do int = %d\n", sizeof(int));
    printf ("tamanho do float = %d\n", sizeof(float));
    printf ("tamanho do char = %d\n", sizeof(char));
    printf ("tamanho da estrutura s1 = %d\n", sizeof(s));
    printf ("tamanho da estrutura s2 = %d\n", sizeof(t));
    printf ("tamanho da estrutura s3 = %d\n", sizeof(u)); 
    printf ("tamanho da estrutura s4 antes = %d\n", sizeof(x));
 

    printf ("digite o tamanho do vetor da estrutura:  ");
    scanf ("%d", &n);

    x.v= (int *) malloc (n*sizeof(int));
    x.n =n;
    printf ("tamanho da estrutura s4 depois = %d\n", sizeof(x));


    ps1 = (struct s1*)malloc (sizeof(struct s1));
    ps2 = (struct s2*)malloc (sizeof(struct s2));
 
return 0;
}