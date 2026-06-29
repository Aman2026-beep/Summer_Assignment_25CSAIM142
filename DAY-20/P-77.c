#include <stdio.h>

int main() {
    int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 2;

    int matrixA[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int matrixB[3][2] = {
        {7, 8},
        {9, 1},
        {2, 3}
    };

    int result[2][2];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] = result[i][j] + (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }

    printf("Resultant Matrix (Multiplication):\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}