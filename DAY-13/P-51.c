#include <stdio.h>
int main() 
{
    int n, i;

  
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int largest = arr[0];
    int smallest = arr[0];

    for(i = 1; i < n; i++) 
    {
        if(arr[i] > largest)
        {
            largest = arr[i]; 
        }
        if(arr[i] < smallest)
        {
            smallest = arr[i]; 
        }
    }

    printf("\nLargest element = %d", largest);
    printf("\nSmallest element = %d\n", smallest);

    return 0;
}