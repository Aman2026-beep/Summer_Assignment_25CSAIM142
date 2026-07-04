#include <stdio.h>
#include <string.h>

int main() {
    char strings[3][100] = {
        "apple",
        "maple",
        "purple"
    };
    
    int num_strings = 3;
    int global_min[256];

    for (int i = 0; i < 256; i++) {
        global_min[i] = 100000;
    }

    for (int i = 0; i < num_strings; i++) {
        int current_count[256] = {0};

        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strings[i][j] != '\n') {
                int index = (unsigned char)strings[i][j];
                current_count[index]++;
            }
        }

        for (int c = 0; c < 256; c++) {
            if (current_count[c] < global_min[c]) {
                global_min[c] = current_count[c];
            }
        }
    }

    printf("Common characters: ");
    int found_common = 0;
    
    for (int i = 0; i < 256; i++) {
        if (global_min[i] > 0 && global_min[i] != 100000) {
            for (int count = 0; count < global_min[i]; count++) {
                printf("%c ", i);
                found_common = 1;
            }
        }
    }

    if (found_common == 0) {
        printf("None");
    }
    printf("\n");

    return 0;
}