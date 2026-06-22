#include <stdio.h>
#include <limits.h>
int main()
{
    int numbers[] = {12, 45, 7, 93, 28, 93, 51};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int first_largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < size; i++) 
    {
        if (numbers[i] > first_largest) 
        {
            second_largest = first_largest;
            first_largest = numbers[i];
        } 
        else if (numbers[i] > second_largest && numbers[i] != first_largest)
        {
            second_largest = numbers[i];
        }
    }

    if (second_largest == INT_MIN) 
    {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", second_largest);
    }

    return 0;
}
