#include <stdio.h>

int main() {
    char str[200];
    int max_len = 0;
    int max_start_index = 0;
    
    int current_len = 0;
    int current_start_index = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (current_len == 0) {
                current_start_index = i;
            }
            current_len++;
        } 
        else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start_index = current_start_index;
            }
            current_len = 0; 
        }
        i++;
    }

    if (current_len > max_len) {
        max_len = current_len;
        max_start_index = current_start_index;
    }

    if (max_len > 0) {
        printf("The longest word is: ");
        for (int k = 0; k < max_len; k++) {
            printf("%c", str[max_start_index + k]);
        }
        printf("\nLength: %d\n", max_len);
    } else {
        printf("No words found.\n");
    }

    return 0;
}n