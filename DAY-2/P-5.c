#include <stdio.h>

int main() {
    int number, remainder, sum = 0;

   
    printf("Enter an integer: ");
    scanf("%d", &number);

    
    int originalNumber = number;
    if (number < 0) {
        number = -number;
    }

    
    while (number > 0) {
        remainder = number % 10; 
        sum = sum + remainder;   
        number = number / 10;    
    }

    printf("The sum of the digits of %d is: %d\n", originalNumber, sum);

    return 0;
}