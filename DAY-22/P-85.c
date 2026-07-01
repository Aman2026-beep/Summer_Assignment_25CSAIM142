#include <stdio.h>

int main() 
{
    char str[100];
    int length = 0;
    int is_palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[length] != '\0')
 {
        length++;
    }

    if (length > 0 && str[length - 1] == '\n') 
{
        str[length - 1] = '\0';
        length--;
    }

    int start = 0;
    int end = length - 1;

    while (start < end)
 {
        if (str[start] != str[end]) 
{
            is_palindrome = 0;
            break; 
        }
        start++;
        end--;
    }

    if (is_palindrome == 1)
 {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}