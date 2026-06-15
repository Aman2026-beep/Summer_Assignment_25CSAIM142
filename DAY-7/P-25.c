#include <stdio.h>
long long factorial(int n);

int main() {
    int number = 5;

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else
    {
        printf("Factorial of %d is %lld\n", number, factorial(number));
    }
    
    return 0;
}
long long factorial(int n)
{

    if (n <= 1) 
    {
        return 1;
    }
    
    else {
        return n * factorial(n - 1);
    }
}