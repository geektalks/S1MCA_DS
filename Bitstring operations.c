#include <stdio.h>
#include <stdlib.h>

#define SET_SIZE 32 // Assume 32-bit integers

// Set operations
void initialize(int set[]) {
    for (int i = 0; i < SET_SIZE; i++)
        set[i] = 0;
}

void addElement(int set[], int element) {
    set[element] = 1;
}

void removeElement(int set[], int element) {
    set[element] = 0;
}

int isElement(int set[], int element) {
    return set[element];
}

void unionSet(int set1[], int set2[], int resultSet[]) {
    for (int i = 0; i < SET_SIZE; i++)
        resultSet[i] = set1[i] || set2[i];
}

void intersectionSet(int set1[], int set2[], int resultSet[]) {
    for (int i = 0; i < SET_SIZE; i++)
        resultSet[i] = set1[i] && set2[i];
}

void printSet(int set[]) {
    printf("{ ");
    for (int i = 0; i < SET_SIZE; i++) {
        if (set[i] == 1)
            printf("%d ", i);
    }
    printf("}\n");
}

int main() {
    int set1[SET_SIZE], set2[SET_SIZE], resultSet[SET_SIZE];

    initialize(set1);
    initialize(set2);

    addElement(set1, 3);
    addElement(set1, 5);
    addElement(set1, 7);

    addElement(set2, 2);
    addElement(set2, 3);
    addElement(set2, 6);

    printf("Set 1: ");
    printSet(set1);

    printf("Set 2: ");
    printSet(set2);

    unionSet(set1, set2, resultSet);
    printf("Union: ");
    printSet(resultSet);

    intersectionSet(set1, set2, resultSet);
    printf("Intersection: ");
    printSet(resultSet);

    return 0;
}
