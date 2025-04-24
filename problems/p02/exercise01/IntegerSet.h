#ifndef INTEGER_SET_H
#define INTEGER_SET_H

struct NodeElement_ {
    int data;
    struct NodeElement_* next;
} typedef NodeElement;

struct IntegerSet_ {
    NodeElement* elementList;
    int size;
} typedef IntegerSet;

IntegerSet* createIntegerSet();
void insertElement(IntegerSet* set, int element);
IntegerSet* unionSet(IntegerSet* set1, IntegerSet* set2);
IntegerSet* intersectionSet(IntegerSet* set1, IntegerSet* set2);
void freeSet(IntegerSet* set);
void printSet(IntegerSet* set);

#endif
