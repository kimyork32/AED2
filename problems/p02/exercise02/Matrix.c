#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Matrix.h"

Matrix* createMatrix(int rowSize, int columnSize) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rowSize = rowSize;
    matrix->columnSize = columnSize;
    matrix->arr = (int**)malloc(sizeof(int*) * rowSize);

    for (int i = 0; i < rowSize; i++) {
        matrix->arr[i] = (int*)malloc(sizeof(int) * columnSize);
    }

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < columnSize; j++) {
            matrix->arr[i][j] = 0;
        }
    }
    return matrix;
}

void insertElement(Matrix* matrix, int element, int posI, int posJ) {
    assert(posI >= 0 && posI < matrix->rowSize);
    assert(posJ >= 0 && posJ < matrix->columnSize);
    
    matrix->arr[posI][posJ] = element;
}

Matrix* multiplicationMatrix(Matrix* matrix1, Matrix* matrix2) {
    assert(matrix1->columnSize == matrix2->rowSize);

    Matrix* result = createMatrix(matrix1->rowSize, matrix2->columnSize);

    for (int i = 0; i < matrix1->rowSize; i++) {
        for (int j = 0; j < matrix2->columnSize; j++) {
            result->arr[i][j] = 0;
            for (int k = 0; k < matrix1->columnSize; k++) {
                result->arr[i][j] += matrix1->arr[i][k] * matrix2->arr[k][j];
            }
        }
    }
    return result;
}

Matrix* additionMatrix(Matrix* matrix1, Matrix* matrix2) {
    assert(matrix1->rowSize == matrix2->rowSize);
    assert(matrix1->columnSize == matrix2->columnSize);

    Matrix* result = createMatrix(matrix1->rowSize, matrix1->columnSize);

    for (int i = 0; i < matrix1->rowSize; i++) {
        for (int j = 0; j < matrix1->columnSize; j++) {
            result->arr[i][j] = matrix1->arr[i][j] + matrix2->arr[i][j];
        }
    }
    return result;
}

void freeMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rowSize; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}

void printMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rowSize; i++) {
        for (int j = 0; j < matrix->columnSize; j++) {
            printf("%d ", matrix->arr[i][j]);
        }
        printf("\n");
    }
}
