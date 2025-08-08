#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;        
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);        
        quickSort(arr, pi + 1, high);        
    }
}
void printArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}

OUTPUT :
Enter number of elements: 7
Enter 7 elements:
1 4 2 7 5  3 9
Sorted Array: 1 2 3 4 5 7 9 
