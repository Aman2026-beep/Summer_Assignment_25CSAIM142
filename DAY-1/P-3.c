#include <stdio.h>

int main() {
    int n;
    long long factorial = 1;
    
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Factorial does not exist for negative numbers.");
    } else {
        for(int i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("Factorial of %d = %lld\n", n, factorial);
    }
    
    return 0;
}