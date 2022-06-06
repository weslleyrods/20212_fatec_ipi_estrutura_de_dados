#include <stdio.h> 

int main() {

    int i;
    float f;

    for (i=1, f=1.0; i<14; i++){
    f = f * i;
    printf ("Fatoraial de %d = %.0f\n", i, f);}
    
return 0;

}
