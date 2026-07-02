#include <stdio.h>

int main() {
    char str[200];
    int frequency[256] = {0};
    char result = '\0';

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n') {
            int index = (unsigned char)str[i];
            frequency[index]++;
            
            if (frequency[index] > 1) {
                result = str[i];
                break;
            }
        }
    }

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}n