#include <stdio.h>
int main() 
{
    int arr1[50], arr2[50], unionArr[100];
    int size1, size2, i, j, k = 0, isDuplicate;

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
        isDuplicate = 0;
        for(j = 0; j < k; j++)
        {
            if(arr1[i] == unionArr[j])
            {
                isDuplicate = 1;
                break;
            }
        }
        if(isDuplicate == 0)
        {
            unionArr[k] = arr1[i];
            k++;
        }
    }

    for(i = 0; i < size2; i++)
    {
        isDuplicate = 0;
        for(j = 0; j < k; j++)
        {
            if(arr2[i] == unionArr[j]) 
            {
                isDuplicate = 1;
                break;
            }
        }
        if(isDuplicate == 0) 
        {
            unionArr[k] = arr2[i];
            k++;
        }
    }

    printf("\nThe Union of the two arrays is:\n");
    for(i = 0; i < k; i++)
    {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}s