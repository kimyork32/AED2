#include <stdlib.h>
#include <stdio.h>
#include "IntegerSet.h"

IntegerSet* createIntegerSet()  {
    IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
    set->elementList = NULL;
    set->size = 0;
    return set;
}

void insertElement(IntegerSet* set, int element) {
    NodeElement* node = (NodeElement*)malloc(sizeof(NodeElement));
    node->data = element;
    node->next = NULL;

    if (!set->elementList) {
        set->elementList = node;
        set->size++;
    }
    else {
        NodeElement* current = set->elementList;
        NodeElement* prev = NULL;
        while (current) {
            if (current->data == element) {
                free(node);
                return;
            }
            prev = current;
            current = current->next;
        }
        prev->next = node;
        set->size++;
    }
}

IntegerSet* unionSet(IntegerSet* set1, IntegerSet* set2) {
    IntegerSet* setResult = createIntegerSet();
    NodeElement* current = set1->elementList;
    while (current) {
        insertElement(setResult, current->data);
        current = current->next;
    }

    current = set2->elementList;

    while (current) {
        insertElement(setResult, current->data);
        current = current->next;
    }
    return setResult;
}

IntegerSet* intersectionSet(IntegerSet* set1, IntegerSet* set2) {
    IntegerSet* setResult = createIntegerSet();
    NodeElement* current1 = set1->elementList;
    NodeElement* current2 = set2->elementList;
    while (current1) {
        while (current2) {
            if (current1->data == current2->data) {
                insertElement(setResult, current1->data);
            }
            current2 = current2->next;
        }
        current2 = set2->elementList;
        current1 = current1->next;
    }
    return setResult;
}

void freeSet(IntegerSet* set) {
    NodeElement* current = set->elementList;
    while (current) {
        NodeElement* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

void printSet(IntegerSet* set) {
    NodeElement* current = set->elementList;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
