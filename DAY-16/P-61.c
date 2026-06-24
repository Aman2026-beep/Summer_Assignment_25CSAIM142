#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6; 
    
    int expected_total = (n * (n + 1)) / 2;
    
    int actual_total = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        actual_total += arr[i];
    }
    
    int missing_number = expected_total - actual_total;
    
    printf("The missing number is: %d\n", missing_number);
    
    return 0;
}