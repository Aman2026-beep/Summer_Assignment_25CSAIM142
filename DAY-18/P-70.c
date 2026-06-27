#include <stdio.h>
int main()
{
    int numbers[] = {29, 64, 73, 12, 5, 22};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++) 
        {
            if (numbers[j] < numbers[min_index]) 
            {
                min_index = j;
            }
        }

        int temp = numbers[min_index];
        numbers[min_index] = numbers[i];
        numbers[i] = temp;
    }

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}