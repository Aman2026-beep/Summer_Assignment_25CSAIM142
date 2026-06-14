#include <stdio.h>
#include <math.h>
int main() 
{
    long long binary;
    int decimal = 0, i = 0, rem;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary != 0) {
        rem = binary % 10;
        decimal += rem * pow(2, i);
        binary /= 10;
        i++;
    }

    printf("Decimal: %d\n", decimal);
    return 0;
}