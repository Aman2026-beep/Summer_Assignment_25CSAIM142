#include <stdio.h>
int main() 
{
    int arr1[50], arr2[50], commonArr[50];
    int size1, size2, i, j, l, k = 0, isDuplicate;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    printf("Enter %d elements for the first array:\n", size1);
    for(i = 0; i < size1; i++) 
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    printf("Enter %d elements for the second array:\n", size2);
    for(i = 0; i < size2; i++) 
    {
        scanf("%d", &arr2[i]);
    }

    for(i = 0; i < size1; i++) 
    {
        for(j = 0; j < size2; j++) 
        {
            if(arr1[i] == arr2[j]) 
            {
                
                isDuplicate = 0;
                for(l = 0; l < k; l++)
                {
                    if(arr1[i] == commonArr[l])
                    {
                        isDuplicate = 1;
                        break;
                    }
                }

                if(isDuplicate == 0)
                {
                    commonArr[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }

    printf("\nThe common elements are:\n");
    if(k == 0) {
        printf("No common elements found.");
    } else {
        for(i = 0; i < k; i++) 
        {
            printf("%d ", commonArr[i]);
        }
    }
    printf("\n");

    return 0;
}