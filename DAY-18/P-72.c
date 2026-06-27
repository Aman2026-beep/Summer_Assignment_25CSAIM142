#include <stdio.h>
int main()
{
    int numbers[] = {15, 3, 82, 24, 61, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (numbers[j] < numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("Array sorted in descending order: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}nN