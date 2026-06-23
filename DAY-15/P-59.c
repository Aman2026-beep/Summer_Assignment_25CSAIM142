#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int last_element = arr[size - 1];

    for (int i = size - 1; i > 0; i--) 
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last_element;

    printf("Array after Right Rotation: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}