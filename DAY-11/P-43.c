#include <stdio.h>
int isPrime(int num);
int main() 
{
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (isPrime(number) == 1)
 {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is NOT a prime number.\n", number);
    }

    return 0;
}
int isPrime(int num) 
{
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) 
        {
            return 0; 
        }
    }
    return 1; 
}