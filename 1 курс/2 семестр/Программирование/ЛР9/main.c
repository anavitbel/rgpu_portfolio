#include <stdio.h>
#include <stdlib.h>
#include "memalloc.h"
#include "mmult.h"
#include "memfree.h"
#include "print.h"

int main()
{
    int m1, n1;
    int **A;
    printf("Enter sizes of first matrix in 'm n' - format: ");
    if (scanf("%d %d", &m1, &n1)){
        A = createMatrix(m1, n1);
    }
    else return -1;

    int m2, n2;
    int** B;
    printf("Enter sizes of second matrix in 'm n' - format: ");
    if (scanf("%d %d", &m2, &n2)){
        B = createMatrix(m2, n2);
    }
    else return -1;

    int** AmB = mmult(A, m1, n1, B, m2, n2);
    printM(AmB, m1, n2);

    int n;
    int* a;
    printf("Enter size of array: ");
    if (scanf("%d", &n)){
        a = createArray(n);
    }
    else return -1;

    printA(a, n);

    freeM(A, m1);
    freeM(B, m2);
    freeM(AmB, m1);
    freeA(a);
    return 0;
}
