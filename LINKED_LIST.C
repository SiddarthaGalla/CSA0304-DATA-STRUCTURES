#include <stdio.h>
#define SIZE 5
struct Node {
    int data;
    int next;
};
struct Node list[SIZE];
int head = -1;
int freeIndex = 0;
void initialize() {
    for (int i = 0; i < SIZE - 1; i++)
        list[i].next = i + 1;
    list[SIZE - 1].next = -1;
}
void insert(int value) {
    if (freeIndex == -1) {
        printf("List is full!\n");
        return;
    }
    int newNode = freeIndex;
    freeIndex = list[freeIndex].next;
    list[newNode].data = value;
    list[newNode].next = -1;
    if (head == -1)
        head = newNode;
    else {
        int temp = head;
        while (list[temp].next != -1)
            temp = list[temp].next;
        list[temp].next = newNode;
    }
}
void display() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }
    int temp = head;
    printf("SLL: ");
    while (temp != -1) {
        printf("%d ", list[temp].data);
        temp = list[temp].next;
    }
    printf("\n");
}
int main() {
    initialize();
    insert(10);
    insert(20);
    insert(30);
    display();  
    return 0;
}

OUTPUT :
SLL: 10 20 30 
