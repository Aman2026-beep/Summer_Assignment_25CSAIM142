#include <stdio.h>
#include <string.h>

void clear_buffer() {
    while (getchar() != '\n');
}

void read_string(char *str, int max_size) {
    fgets(str, max_size, stdin);
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char str1[200];
    char str2[200];
    char result[400];
    int choice;

    do {
        printf("\n==================================\n");
        printf("     STRING OPERATIONS SYSTEM     \n");
        printf("==================================\n");
        printf("1. Concatenate Two Strings\n");
        printf("2. Find Length of a String\n");
        printf("3. Reverse a String\n");
        printf("4. Compare Two Strings\n");
        printf("5. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            clear_buffer(); 
            continue;
        }
        clear_buffer(); 

        switch (choice) {
            case 1:
                printf("\nEnter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string: ");
                read_string(str2, sizeof(str2));

                strcpy(result, str1);
                strcat(result, str2);

                printf("\nResulting Combined String: \"%s\"\n", result);
                break;

            case 2:
                printf("\nEnter the string: ");
                read_string(str1, sizeof(str1));
                
                printf("\nThe length of the string is: %lu characters\n", strlen(str1));
                break;

            case 3:
                printf("\nEnter string to reverse: ");
                read_string(str1, sizeof(str1));

                int len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[len - 1 - i];
                    str1[len - 1 - i] = temp;
                }

                printf("\nReversed String: \"%s\"\n", str1);
                break;

            case 4:
                printf("\nEnter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string: ");
                read_string(str2, sizeof(str2));

                int comp_result = strcmp(str1, str2);
                if (comp_result == 0) {
                    printf("\nResult: Both strings are exactly identical.\n");
                } else if (comp_result > 0) {
                    printf("\nResult: The first string is greater than the second string alphabetically.\n");
                } else {
                    printf("\nResult: The second string is greater than the first string alphabetically.\n");
                }
                break;

            case 5:
                printf("\nExiting System Application. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please pick a number from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}