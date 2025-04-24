#include <stdio.h>
#include "Matrix.h"

int main() {
    Matrix* matrix1 = createMatrix(2, 3);
    Matrix* matrix2 = createMatrix(3, 2);

    Matrix* matrix3 = createMatrix(2, 3);

    insertElement(matrix1, 1, 0, 0);
    insertElement(matrix1, 2, 0, 1);
    insertElement(matrix1, 3, 0, 2);
    insertElement(matrix1, 4, 1, 0);
    insertElement(matrix1, 5, 1, 1);
    insertElement(matrix1, 6, 1, 2);

    insertElement(matrix2, 7, 0, 0);
    insertElement(matrix2, 8, 0, 1);
    insertElement(matrix2, 9, 1, 0);
    insertElement(matrix2, 10, 1, 1);
    insertElement(matrix2, 11, 2, 0);
    insertElement(matrix2, 12, 2, 1);

    insertElement(matrix3, 1, 0, 0);
    insertElement(matrix3, 1, 0, 1);
    insertElement(matrix3, 1, 0, 2);
    insertElement(matrix3, 1, 1, 0);
    insertElement(matrix3, 1, 1, 1);
    insertElement(matrix3, 1, 1, 2);

    printf("matrix1:\n");
    printMatrix(matrix1);

    printf("matrix2:\n");
    printMatrix(matrix2);

    printf("matrix3:\n");
    printMatrix(matrix3);

    Matrix* resultAdd = additionMatrix(matrix1, matrix3);
    printf("sum of matrix1 and matrix3:\n");
    printMatrix(resultAdd);

    Matrix* resultMul = multiplicationMatrix(matrix1, matrix2);
    printf("multiplication of matrix1 and matrix2:\n");
    printMatrix(resultMul);

    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(matrix3);
    freeMatrix(resultAdd);
    freeMatrix(resultMul);

    return 0;
}
