#include <stdio.h>

int isPalindrome(int num)
{
    int original = num, reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return (original == reversed);
}

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (isPalindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);

    return 0;
}