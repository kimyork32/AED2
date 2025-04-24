#ifndef MATRIX_H 
#define MATRIX_H

struct Matrix_ {
    int** arr;
    int rowSize;
    int columnSize;
} typedef Matrix;

Matrix* createMatrix(int rowSize, int columnSize);
void insertElement(Matrix* matrix, int element, int posI, int posJ);
Matrix* multiplicationMatrix(Matrix* matrix1, Matrix* matrix2);
Matrix* additionMatrix(Matrix* matrix1, Matrix* matrix2);
void freeMatrix(Matrix* matrix);
void printMatrix(Matrix* matrix);

#endif
