#include <stdio.h>
#define MAX_SIZE 100

void hadamardProduct(int u[], int v[], int had[], int n) {
    for(int i=0; i<n; i++) {
       had[i] = u[i] * v[i];
    }
}

void dotProduct(int had[], int* dot, int n) {
    *dot = 0;
    for(int i=0; i<n; i++) {
        *dot += had[i];
    }
}

void insertData(int vect[], int n) {
    for(int i=0; i<n; i++)
        scanf("%d", &vect[i]);
}

void printVector(int vect[], int n) {
    for(int i=0; i<n; i++)
        printf("%d ", vect[i]);
    printf("\n");
}
int main() {
    int u[MAX_SIZE], v[MAX_SIZE], Hadamard[MAX_SIZE], dot, n1, n2;
    printf("Insert size of u: ");
    scanf("%d", &n1);

    printf("Insert size of v: ");
    scanf("%d", &n2);

    if(n1 != n2) {
        printf("size of u and v are different\n");
        return 0;
    }
    
    printf("insert data of u:\n");
    insertData(u, n1);
    printf("insert data of u:\n");
    insertData(v, n2);

    hadamardProduct(u, v, Hadamard, n1);
    dotProduct(Hadamard, &dot, n1);

    printf("Hadamard vector is:\n");
    printVector(Hadamard, n1);


    printf("Dot product is: %d\n", dot);
    return 0;
}
