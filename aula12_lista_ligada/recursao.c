#include <stdio.h>

int fibonacci (int n) {
    if (n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main () {
    int i;
    for (i=0; i<=47; i++)
        printf ("fibonacci de %d = %d\n", i, fibonacci(i));
    return 0;
}