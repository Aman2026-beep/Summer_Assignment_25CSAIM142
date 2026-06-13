#include <stdio.h>

int main() 
{
    int num, largest = -1;

    printf("Enter a number: ");
    scanf("%d", &num);

    int n = num;
    while (n % 2 == 0) 
    {
        largest = 2;
        n /= 2;
    }


    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    if (n > 2)
    {
        largest = n;
    }

    printf("The largest prime factor is: %d\n", largest);

    return 0;
}