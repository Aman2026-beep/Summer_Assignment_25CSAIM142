#include <stdio.h>
int main()
{
    int numbers[] = {2, 4, 7, 2, 8, 4, 9, 2};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int has_duplicates = 0;

    printf("Duplicate elements in the array: \n");

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[i] == numbers[j]) 
            {
                
                int already_counted = 0;
                for (int k = 0; k < i; k++)
                {
                    if (numbers[k] == numbers[i])
                    {
                        already_counted = 1;
                        break;
                    }
                }
                
                if (!already_counted) 
                {
                    printf("%d\n", numbers[i]);
                    has_duplicates = 1;
                }
                break; 
            }
        }
    }

    if (!has_duplicates) 
    {
        printf("No duplicate elements found.\n");
    }

    return 0;
}