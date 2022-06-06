#include <stdio.h>

    typedef struct fracao {
int num;
int den;
} t_fracao;

void mostra_fracao (char *msg, t_fracao f);
void  preenche_f( t_fracao *f);
int compara_f(t_fracao, t_fracao);

int main(){

    t_fracao f1, f2;
    char msg [] = "Fracao:\n";

    preenche_f ( &f1) ;
    mostra_fracao( msg, f1);
    preenche_f ( &f2) ;
    mostra_fracao( msg, f2);
    
    printf ("A maior fracao e: %d\n", compara_f (f1, f2));
    return 0;  
}

void mostra_fracao (char *msg, t_fracao f) {
printf ("\n%s: %d/%d\n", msg, f.num, f.den);
}

void preenche_f (t_fracao *f) {
printf("Digite o numerador da fracao: ");
    scanf("%d", &f->num);
printf("Digite o denominador da fracao: ");
    scanf("%d", &f->den);
}

int compara_f (t_fracao f1, t_fracao f2){
    int cp1, cp2;
    cp1 = f1.num * f2.den;
    cp2 = f2.num * f1.den;

    if (cp1 > cp2)
        return 1;
    else if (cp2 > cp1)
        return 2;
    else return 0;
}