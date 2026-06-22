#include <stdio.h>
int main() 
{
    int numbers[] = {12, 45, 7, 93, 28, 51};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target;
    int foundIndex = -1; 
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) 
    {
        if (numbers[i] == target) 
        {
            foundIndex = i; 
            break;         
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