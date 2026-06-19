#include <stdio.h>
int addNumbers(int num1, int num2);

int main() 
{
    int x, y, result;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    result = addNumbers(x, y);

    printf("The sum is: %d\n", result);

    return 0;
}
int addNumbers(int num1, int num2) {
    int sum;
    
    sum = num1 + num2; 
    
    return sum;        
}