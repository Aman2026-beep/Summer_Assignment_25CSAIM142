#include <stdio.h>
int fibonacci(int n);

int main()
{
    int n = 7; 

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        printf("Fibonacci number at position %d is: %d\n", n, fibonacci(n));
    }

    return 0;
}
int fibonacci(int n) 
{

    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}