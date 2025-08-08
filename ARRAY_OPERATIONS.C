#include <stdio.h>

int main() {
    int arr[100], n = 0, choice, value, pos, i;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);

            for (i = n; i > pos; i--)
                arr[i] = arr[i - 1];

            arr[pos] = value;
            n++;
            printf("Value inserted.\n");
        }
        else if (choice == 2) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            for (i = pos; i < n - 1; i++)
                arr[i] = arr[i + 1];
            n--;
            printf("Value deleted.\n");
        }
        else if (choice == 3) {
            printf("Array: ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

OUTPUT :
1.Insert  2.Delete  3.Display  4.Exit
Enter your choice: 1
Enter valzue: 17
Enter position: 6
Value inserted.

1.Insert  2.Delete  3.Display  4.Exit
Enter your choice: 2
Enter position to delete: 6
Value deleted.
