#include <stdio.h>
int main()
{
    int n, i;
    int binaryNum[32];

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n == 0) 
    {
        printf("Binary representation: 0\n");
        return 0;
    }

    i = 0;
    while (n > 0)
    {
        
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("Binary representation: ");
    for (int j = i - 1; j >= 0; j--) 
    {
        printf("%d", binaryNum[j]);
    }
    printf("\n");

    return 0;
}