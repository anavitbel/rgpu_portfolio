#include <stdio.h>
#include <stdlib.h>
#include "memfree.h"

void freeM(int **M, int m) {
    for (int i = 0; i < m; i++)
        free(M[i]);
    free(M);
}

void freeA(int *A) {
    free(A);
}
