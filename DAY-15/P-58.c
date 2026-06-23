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

    int first_element = arr[0];

    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = first_element;

    printf("Array after Left Rotation: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}