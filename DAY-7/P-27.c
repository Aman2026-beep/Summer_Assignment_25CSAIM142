#include <stdio.h>
int sumOfDigits(int n);

int main() 
{
    int number = 12345;
    int result = sumOfDigits(number < 0 ? -number : number);
    
    printf("The sum of digits of %d is %d\n", number, result);
    
    return 0;
}
int sumOfDigits(int n) 
{
        if (n == 0) 
        {
        return 0;
    }
    
   
    return (n % 10) + sumOfDigits(n / 10);
}