#include <stdio.h>

int main()
{
    int number, digit;
    int product = 1;

    printf("Enter an integer: ");
    scanf("%d", &number);


    if (number < 0)
    {
        number = -number;
    }


    if (number == 0)
    {
        product = 0;
    } else 
    {
        while (number > 0) {
            digit = number % 10;       
            product = product * digit; 
            number = number / 10;      
        }
    }

    printf("Product of the digits is: %d\n", product);

    return 0;
}