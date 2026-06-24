#include <stdio.h>

int main()
 {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array after removing duplicates: ");
    
    for (int i = 0; i < size; i++) 
{
        int is_duplicate = 0;
        
        for (int j = 0; j < i; j++) 
{
            if (arr[i] == arr[j])
 {
                is_duplicate = 1;
                break;
            }
        }
        
        if (is_duplicate == 0)
 {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
    return 0;
}