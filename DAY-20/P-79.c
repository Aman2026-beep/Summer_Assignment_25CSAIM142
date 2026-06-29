#include <stdio.h>

int main() {
    int rows = 3;
    int cols = 3;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nRow-wise Sums:\n");
    for (int i = 0; i < rows; i++) {
        int row_sum = 0;

        for (int j = 0; j < cols; j++) {
            row_sum = row_sum + matrix[i][j];
        }

        printf("Sum of Row %d = %d\n", i + 1, row_sum);
    }

    return 0;
}