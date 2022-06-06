#include <stdio.h>
#include <stdlib.h>

struct no_bin {
    int info;
    struct no_bin * esq;
    struct no_bin * dir;
};

struct no_bin * cria_no_bin(int);