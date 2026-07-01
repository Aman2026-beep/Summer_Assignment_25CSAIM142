#include <stdio.h>

int main()
 {
    char str[200];
    int count = 0;
    int in_word = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) 
{
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
 {
            in_word = 0;
        } 
        else if (in_word == 0)
 {
            in_word = 1;
            count++;
        }
    }

    printf("Total number of words: %d\n", count);

    return 0;
}