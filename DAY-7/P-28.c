#include <stdio.h>
int reverseNumber(int n, int reversed);

int main() 
{
    int number = 89664;
    
    
    int result = reverseNumber(number, 0);
    
    printf("Original number: %d\n", number);
    printf("Reversed number: %d\n", result);
    
    return 0;
}
int reverseNumber(int n, int reversed)
{
    if (n == 0) {
        return reversed;
    }
    
   return reverseNumber(n / 10, (reversed * 10) + (n % 10));
}