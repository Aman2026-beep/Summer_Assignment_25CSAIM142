#include <stdio.h>

int main() {
    char str[200];
    char compressed[400]; 
    int i = 0;
    int j = 0;

    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    while (str[i] != '\0') {
        char current_char = str[i];
        int count = 0;

        while (str[i] != '\0' && str[i] == current_char) {
            count++;
            i++;
        }

        compressed[j] = current_char;
        j++;

        int temp_j = j;
        int temp_count = count;
        int digits = 0;
        
        while (temp_count > 0) {
            digits++;
            temp_count /= 10;
        }
        
        temp_count = count;
        for (int k = digits - 1; k >= 0; k--) {
            compressed[j + k] = (temp_count % 10) + '0';
            temp_count /= 10;
        }
        j += digits;
    }

    compressed[j] = '\0';

    int comp_len = 0;
    while (compressed[comp_len] != '\0') comp_len++;
    
    int orig_len = 0;
    while (str[orig_len] != '\0') orig_len++;

    if (comp_len < orig_len) {
        printf("Compressed string: %s\n", compressed);
    } else {
        printf("Compressed string: %s\n", str);
    }

    return 0;
}