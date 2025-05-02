#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double*** createArray(int m, int n, int k) {
    assert(m > 0);
    assert(n > 0);
    assert(k > 0);
    double*** v = (double***)malloc(sizeof(double**) * m);
    for (int i = 0; i < m; i++) {
        v[i] = (double**)malloc(sizeof(double*) * n);
        for (int j = 0; j < n; j++) {
            v[i][j] = (double*)malloc(sizeof(double) * k);
        }
    }
    return v;
}

void insertElements(double*** v, int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < k; z++) {
                scanf("%lf", &v[i][j][z]);
            }
        }
    }
}

void printMatrix(double*** v, int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        printf("layer %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < k; z++) {
                printf("%.2lf ", v[i][j][z]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void freeMatrix(double*** v, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(v[i][j]);
        }
        free(v[i]);
    }
    free(v);
}

int main() {
    int m, n, k;
    double*** v;
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    printf("k: ");
    scanf("%d", &k);
    v = createArray(m, n, k);
    insertElements(v, m, n, k);
    printMatrix(v, m, n, k);
    freeMatrix(v, m, n);
    return 0;
}
