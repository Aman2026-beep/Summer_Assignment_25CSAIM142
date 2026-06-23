#include <stdio.h>
int main() 
{

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); 
    
   
    int start = 0;          
    int end = size - 1;     
    int temp;              
    printf("Original Array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (start < end) 
    {
     
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; 
        end--;   
    }

   
    printf("Reversed Array: ");
    for(int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}