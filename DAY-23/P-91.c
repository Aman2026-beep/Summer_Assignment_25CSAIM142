 #include <stdio.h>

int main() {
    char str1[100];
    char str2[100];
    int count1[256] = {0};
    int count2[256] = {0};
    int is_anagram = 1;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != '\n') {
            int index = (unsigned char)str1[i];
            count1[index]++;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] != '\n') {
            int index = (unsigned char)str2[i];
            count2[index]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            is_anagram = 0;
            break;
        }
    }

    if (is_anagram == 1) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}