#include <stdio.h>

int main() {
    char str[200];
    int seen[256] = {0};
    int read_index = 0;
    int write_index = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[read_index] != '\0') {
        int index = (unsigned char)str[read_index];

        if (seen[index] == 0) {
            seen[index] = 1; 
            str[write_index] = str[read_index];
            write_index++;
        }
        read_index++;
    }

    str[write_index] = '\0';

    printf("String after removing duplicates: %s", str);

    return 0;
}