#include <stdio.h>
int main()
{
    int numbers[] = {3, 9, 14, 21, 35, 47, 52, 68, 71};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target;
    int low = 0;
    int high = size - 1;
    int foundIndex = -1;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (numbers[mid] == target)
        {
            foundIndex = mid;
            break; 
        }
        else if (numbers[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (foundIndex != -1) 
    {
        printf("Success! %d found at index position %d.\n", target, foundIndex);
    } else {
        printf("Sorry, %d is not in the array.\n", target);
    }

    return 0;
}