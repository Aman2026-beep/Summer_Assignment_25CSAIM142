#include <stdio.h>
int main()
{
    int rows = 2;
    int cols = 3;

    int original[2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    int transpose[3][2];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = original[i][j];
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", original[i][j]);
        }
        printf("\n");
    }

    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) 
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}