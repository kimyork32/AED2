#include <stdio.h>
#include "IntegerSet.h"

int main() {
    IntegerSet* set1 = createIntegerSet();
    IntegerSet* set2 = createIntegerSet();
    IntegerSet* setUn = NULL;
    IntegerSet* setIn = NULL;

    insertElement(set1, 3);
    insertElement(set1, 6);
    insertElement(set1, 8);
    insertElement(set1, 8);
    insertElement(set1, 1);
    insertElement(set1, 1); 
    insertElement(set1, 0); 
    insertElement(set2, 6);
    insertElement(set2, 2);
    insertElement(set2, 8);
    insertElement(set2, 0);
    insertElement(set2, 10);
    insertElement(set2, 10);

    setUn = unionSet(set1, set2);
    setIn = intersectionSet(set1, set2);

    printf("Set 1:\n");
    printSet(set1);
    printf("Set 2:\n");
    printSet(set2);
    printf("Union of set1 and set2:\n");
    printSet(setUn);
    printf("Intersection of set1 and set2:\n");
    printSet(setIn);

    freeSet(set1);
    freeSet(set2);
    freeSet(setUn);
    freeSet(setIn);
    return 0;
}
