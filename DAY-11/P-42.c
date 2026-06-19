#include <stdio.h>
int findMax(int num1, int num2);
int main() 
{
    int x, y, largest;

    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);
    largest = findMax(x, y);

    printf("The maximum number is: %d\n", largest);

    return 0;
}

int findMax(int num1, int num2) 
{
    if (num1 > num2)
    {
        return num1;
    } else
    {
        return num2;
    }
}