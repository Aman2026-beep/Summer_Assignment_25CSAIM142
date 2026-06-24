#include <stdio.h>
int main() 
{
    int arr[] = {2, 3, 5, 3, 2, 3, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int max_element = arr[0];
    int max_count = 0;
    
    for (int i = 0; i < size; i++) 
    {
        int current_count = 0;
        
        for (int j = 0; j < size; j++) 
        {
            if (arr[i] == arr[j]) {
                current_count++;
            }
        }
        
        if (current_count > max_count)
        {
            max_count = current_count;
            max_element = arr[i];
        }
    }
    
    printf("The element with maximum frequency is: %d\n", max_element);
    printf("It appears %d times.\n", max_count);
    
    return 0;
}