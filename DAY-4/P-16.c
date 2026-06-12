#include <stdio.h>

int main() 
{
   int start, end;
   printf("Enter range (e.g., 100 se 999): ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers between %d and %d:\n", start, end);

    for (int i = start; i <= end; i++) {
        int temp = i, sum = 0;
        
       
        while (temp > 0) {
            int digit = temp % 10;
            sum += (digit * digit * digit);
            temp /= 10;
        }

        if (sum == i) printf("%d ", i);
    }
    return 0;
}