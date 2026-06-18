#include <stdio.h>
int main()
{
    int rows = 5;

    for (int i = 0; i < rows; i++) 
    {
        
        for (int j = 0; j < rows - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) 
        {
            printf("%c", 'A' + k);
        }
        for (int l = i - 1; l >= 0; l--) 
        {
            printf("%c", 'A' + l);
        }
        printf("\n");
    }

    return 0;
}