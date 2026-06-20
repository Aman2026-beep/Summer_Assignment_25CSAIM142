#include <stdio.h>

int isArmstrong(int num) 
{
    int original = num, sum = 0, remainder;

    while (num > 0) 
{
        remainder = num % 10;
        sum = sum + (remainder * remainder * remainder);
        num /= 10;
    }

    return (original == sum);
}

int main()
{
    int num;
    printf("Enter a 3-digit integer: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}