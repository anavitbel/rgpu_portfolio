#include <stdio.h>
#include <stdlib.h>
#include "mmult.h"

int** mmult(int** M1, int m1, int n1, int** M2, int m2, int n2) {
    if (n1 == m2)
    {
        int** M = (int**)malloc(m1 * sizeof(int*));
        for (int i = 0; i < m1; i++)
            M[i] = (int*)malloc(n2 * sizeof(int));
        for (int i = 0; i < m1; i++)
            for (int j = 0; j < n2; j++) {
                M[i][j] = 0;
                for (int r = 0; r < n1; r++)
                    M[i][j] += M1[i][r] * M2[r][j];
            }
        return M;
    } else {
        printf("Multplication isn't possible.");
        return -1;
    }
}
