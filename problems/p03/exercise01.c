#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* createArray(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* getNumPositives(int* arr, int n, int* k) {
    int* newArr = (int*)malloc(sizeof(int) * n);
    int i;
    *k = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            newArr[*k] = arr[i];
            (*k)++;
        }
    }
    newArr = realloc(newArr, sizeof(int) * (*k));
    assert(newArr);
    return newArr;
};

int main() {
    int n, *v, *arrPositives;
    int k = 0;
    printf("n: ");
    scanf("%d", &n);
    v = createArray(n);
    arrPositives = getNumPositives(v, n, &k);
    printArray(arrPositives, k);
    free(v);
    free(arrPositives);
    return 0;
}
