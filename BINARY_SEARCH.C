#include <stdio.h>

int main() {
    int arr[100], n, key, i;
    int low, high, mid;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("%d found at position %d\n", key, mid + 1);
            return 0;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d not found\n", key);
    return 0;
}

OUTPUT:
Enter number of elements: 5
Enter 5 sorted numbers:
14 31 17 23 10 
Enter number to search: 17
17 found at position 3
