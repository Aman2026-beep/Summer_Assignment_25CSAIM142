#include <stdio.h>
#include <string.h>

int main() {
    char str[200] = "The quick brown fox jumps over the lazy dog";
    char words[20][50];
    int word_count = 0;
    
    int i = 0;
    int j = 0;

    printf("Original Sentence: %s\n", str);

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            words[word_count][j] = str[i];
            j++;
        } else {
            if (j > 0) {
                words[word_count][j] = '\0';
                word_count++;
                j = 0;
            }
        }
        i++;
    }
    
    if (j > 0) {
        words[word_count][j] = '\0';
        word_count++;
    }

    char temp[50];
    for (int m = 0; m < word_count - 1; m++) {
        for (int n = 0; n < word_count - m - 1; n++) {
            if (strlen(words[n]) > strlen(words[n + 1])) {
                strcpy(temp, words[n]);
                strcpy(words[n], words[n + 1]);
                strcpy(words[n + 1], temp);
            }
        }
    }

    printf("Words sorted by length: ");
    for (int m = 0; m < word_count; m++) {
        printf("%s ", words[m]);
    }
    printf("\n");

    return 0;
}