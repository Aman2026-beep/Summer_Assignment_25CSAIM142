#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];
    char temp[200] = "";

    printf("Enter the original string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the rotation string: ");
    fgets(str2, sizeof(str2), stdin);

    int len1 = 0;
    while (str1[len1] != '\0') len1++;
    if (len1 > 0 && str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
        len1--;
    }

    int len2 = 0;
    while (str2[len2] != '\0') len2++;
    if (len2 > 0 && str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
        len2--;
    }

    int is_rotation = 0;

    if (len1 == len2 && len1 > 0) {
        strcat(temp, str1);
        strcat(temp, str1);

        if (strstr(temp, str2) != NULL) {
            is_rotation = 1;
        }
    }

    if (is_rotation == 1) {
        printf("The string is a valid rotation.\n");
    } else {
        printf("The string is NOT a valid rotation.\n");
    }

    return 0;
}