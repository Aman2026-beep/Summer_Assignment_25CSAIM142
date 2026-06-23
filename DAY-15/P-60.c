#include <stdio.h>

int main()
{
    int arr[] = {1, 0, 3, 0, 5, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    while (count < size)
    {
        arr[count] = 0;
        count++;
    }

    printf("Array after moving zeros: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}