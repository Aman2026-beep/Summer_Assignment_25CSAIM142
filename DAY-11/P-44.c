#include <stdio.h>
int findFactorial(int num);

int main()
{
    int number, result;
    printf("Enter a positive integer (0 to 12): ");
    scanf("%d", &number);

    if (number < 0) 
    {
        printf("Error: Factorial of a negative number doesn't exist.\n");
    } else if (number > 12) {
        printf("Error: Number too large! Result will overflow a standard int.\n");
    } else
    {
        
        result = findFactorial(number);
        printf("The factorial of %d is: %d\n", number, result);
    }

    return 0;
}

int findFactorial(int num) 
{
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial = factorial * i; 
    }

    return factorial; 
}