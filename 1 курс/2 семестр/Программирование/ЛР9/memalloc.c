#include <stdio.h>
#include <stdlib.h>
#include "memalloc.h"

int** createMatrix(int m, int n)
{
    int **M = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < m; i++)
        M[i] = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("[%d][%d] = ",  i, j);
            scanf("%d", &M[i][j]);
        }
    return M;
}
int* createArray(int n)
{
    int *A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &A[i]);
    }
    return A;
}
