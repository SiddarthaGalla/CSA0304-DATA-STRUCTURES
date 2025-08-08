#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1; 
    else
        return n * factorial(n - 1);  
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("Factorial of %d is %d.\n", num, factorial(num));

    return 0;
}

OUTPUT :
Enter a number: 6
Factorial of 6 is 720.
