#include<stdio.h>
void main()
{
    int r,s=0,n,a;
    printf("enter any no.");
    scanf("%d",&n);
        a=n;
        while(n>0)
        {
            r=n%10;
            s=s*10+r;
            n=n/10;
    
        } printf("%d",s);
        if(s==a)
        { printf("palindrome\t");
        }
        else
        { printf("not palindrome\t");
        }
        
}
