#include <stdio.h>

int main()
 {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[length] != '\0')
 {
        length++;
    }

    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    printf("The length of the string is: %d\n", length);

    return 0;
}