#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    insert(17);
    insert(23);
    insert(8);
    display();
    return 0;
}

OUTPUT :
0 -> -1
1 -> -1
2 -> -1
3 -> 23
4 -> -1
5 -> -1
6 -> -1
7 -> 17
8 -> 8
9 -> -1
