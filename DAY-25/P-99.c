#include <stdio.h>
#include <string.h>

int main() {
    char names[5][50] = {
        "Zara",
        "Alex",
        "Ryan",
        "Emma",
        "John"
    };
    
    int n = 5;
    char temp[50];

    printf("Original list of names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nAlphabetically sorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
} 