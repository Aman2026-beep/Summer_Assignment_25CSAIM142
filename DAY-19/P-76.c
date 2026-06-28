#include <stdio.h>
int main()
{
    int size = 3;

    int matrix[3][3] = 
    {
        {5, 8, 3},
        {1, 9, 7},
        {6, 2, 4}
    };

    int diagonal_sum = 0;

    for (int i = 0; i < size; i++)
    {
        diagonal_sum = diagonal_sum + matrix[i][i];
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of the main diagonal elements: %d\n", diagonal_sum);

    return 0;
}