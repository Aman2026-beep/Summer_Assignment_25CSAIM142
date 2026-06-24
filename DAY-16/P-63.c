#include <stdio.h>
int main() 
{
    int arr[] = {2, 4, 7, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target_sum = 15;
    int found = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] + arr[j] == target_sum) 
            {
                printf("Pair found: %d and %d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    
    if (found == 0) {
        printf("No pair found with the given sum.\n");
    }
    
    return 0;
}