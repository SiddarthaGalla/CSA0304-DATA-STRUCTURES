#include <stdio.h>

int main() {
    int n, a = 0, b = 1, c;

    printf("Enter how many terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}

OUTPUT :
Enter how many terms: 6
Fibonacci Series: 0 1 1 2 3 5 
