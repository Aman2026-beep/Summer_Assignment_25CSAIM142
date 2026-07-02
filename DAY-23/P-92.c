#include <stdio.h>

int main() {
    char str[200];
    int frequency[256] = {0};
    int max_count = 0;
    char max_char = '\0';

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && str[i] != ' ') {
            int index = (unsigned char)str[i];
            frequency[index]++;
        }
    }

    for (int i = 0; str[i] != '\0'; i++) {
        int index = (unsigned char)str[i];
        if (frequency[index] > max_count) {
            max_count = frequency[index];
            max_char = str[i];
        }
    }

    if (max_count > 0) {
        printf("The maximum occurring character is '%c' (appears %d times).\n", max_char, max_count);
    } else {
        printf("The string is empty or contains only spaces.\n");
    }

    return 0;
}