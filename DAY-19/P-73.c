#include <stdio.h>
int main()
{
    int rows = 2;
    int cols = 3;

    int matrixA[2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    int matrixB[2][3] = 
    {
        {7, 8, 9},
        {3, 2, 1}
    };

    int sum[2][3];

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("Resultant Matrix (Sum):\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}