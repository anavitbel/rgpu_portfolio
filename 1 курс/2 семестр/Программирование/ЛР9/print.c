#include <stdio.h>
#include <stdlib.h>
#include "print.h"

void printM(int **M, int m, int n) {
    printf("Multiplication:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            printf("[%d][%d] = %d\t",  i, j, M[i][j]);
        }
        printf("\n");
    }
}

void printA(int *A, int n) {
    printf("Array:\n");
    for (int i = 0; i < n; i++) {
            printf("[%d] = %d\t",  i, A[i]);
        }
}