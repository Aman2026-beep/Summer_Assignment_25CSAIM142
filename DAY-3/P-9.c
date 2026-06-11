#include<stdio.h>
void main()
{
    int i,n;
    printf("Enter any Number");
    scanf("%d",&n);
    for (i=2;i<=n-1;i++)
    { 
        if (n%i==0)
        { printf("not prime");
        break;
        }
    }
    if (i==n)
    { printf("prime");
    }
}
