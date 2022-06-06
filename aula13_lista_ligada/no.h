#include <stdlib.h>
#include <stdio.h>
typedef struct no {
    int info;
    struct no * proximo;
} s_no;

s_no * constroi_no (int);
