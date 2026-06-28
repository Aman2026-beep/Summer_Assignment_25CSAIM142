#include <stdio.h>
int main()
{
    int rows = 3;
    int cols = 2;

    int matrixA[3][2] = 
    {
        {10, 20},
        {30, 40},
        {50, 60}
    };

    int matrixB[3][2] = 
    {
        {2, 4},
        {6, 8},
        {10, 12}
    };

    int difference[3][2];

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            difference[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    printf("Resultant Matrix (Difference):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}