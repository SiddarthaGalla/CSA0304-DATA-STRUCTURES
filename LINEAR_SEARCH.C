#include <stdio.h>

int main() {
    int arr[100], n, i, key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            break;
        }
    }
    if(found)
        printf("%d found at position %d.\n", key, i + 1);
    else
        printf("%d not found in the array.\n", key);
    return 0;
}

OUTPUT:
Enter number of elements: 6
Enter 6 elements:
1 17 06 20 10 31
Enter number to search: 31
31 found at position 6.
