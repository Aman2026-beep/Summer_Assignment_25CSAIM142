#include <stdio.h>

int main() {
    char str[200];
    int read_index = 0;
    int write_index = 0;

    printf("Enter a string with spaces: ");
    fgets(str, sizeof(str), stdin);

    while (str[read_index] != '\0') {
        if (str[read_index] != ' ' && str[read_index] != '\t') {
            str[write_index] = str[read_index];
            write_index++;
        }
        read_index++;
    }
    
    str[write_index] = '\0';

    printf("String after removing spaces: %s", str);

    return 0;
}