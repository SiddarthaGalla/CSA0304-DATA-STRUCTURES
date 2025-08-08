#include <stdio.h>

#define MAX 100

typedef struct Node {
    int key, height;
    int left, right; // indices in array, -1 means NULL
} Node;

Node tree[MAX];
int size = 0;

int newNode(int key) {
    tree[size].key = key;
    tree[size].height = 1;
    tree[size].left = tree[size].right = -1;
    return size++;
}

int height(int i) {
    return (i == -1) ? 0 : tree[i].height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotations
int rotateRight(int y) {
    int x = tree[y].left;
    int T2 = tree[x].right;

    tree[x].right = y;
    tree[y].left = T2;

    tree[y].height = max(height(tree[y].left), height(tree[y].right)) + 1;
    tree[x].height = max(height(tree[x].left), height(tree[x].right)) + 1;

    return x;
}

int rotateLeft(int x) {
    int y = tree[x].right;
    int T2 = tree[y].left;

    tree[y].left = x;
    tree[x].right = T2;

    tree[x].height = max(height(tree[x].left), height(tree[x].right)) + 1;
    tree[y].height = max(height(tree[y].left), height(tree[y].right)) + 1;

    return y;
}

int getBalance(int i) {
    return (i == -1) ? 0 : height(tree[i].left) - height(tree[i].right);
}

int insert(int root, int key) {
    if (root == -1) return newNode(key);

    if (key < tree[root].key)
        tree[root].left = insert(tree[root].left, key);
    else if (key > tree[root].key)
        tree[root].right = insert(tree[root].right, key);
    else
        return root;

    tree[root].height = 1 + max(height(tree[root].left), height(tree[root].right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < tree[tree[root].left].key)
        return rotateRight(root);
    // RR
    if (balance < -1 && key > tree[tree[root].right].key)
        return rotateLeft(root);
    // LR
    if (balance > 1 && key > tree[tree[root].left].key) {
        tree[root].left = rotateLeft(tree[root].left);
        return rotateRight(root);
    }
    // RL
    if (balance < -1 && key < tree[tree[root].right].key) {
        tree[root].right = rotateRight(tree[root].right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(int root) {
    if (root != -1) {
        inorder(tree[root].left);
        printf("%d ", tree[root].key);
        inorder(tree[root].right);
    }
}

int search(int root, int key) {
    if (root == -1) return -1;
    if (tree[root].key == key) return root;
    if (key < tree[root].key)
        return search(tree[root].left, key);
    else
        return search(tree[root].right, key);
}

int main() {
    int root = -1;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 40);

    printf("Inorder: ");
    inorder(root);

    int found = search(root, 25);
    printf("\nSearch 25: %s", found != -1 ? "Found" : "Not Found");

    return 0;
}

OUTPUT:
Inorder: 10 20 25 30 40 
Search 25: Found
