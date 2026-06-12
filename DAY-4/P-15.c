#include<stdio.h>
void main()
{
    int n,c,r,arm=0;
    printf("enter any value of n\t");
    scanf("%d",&n);
         c=n;
         while(n>0)
         {
             r=n%10;
             arm=(r*r*r)+arm;
             n=n/10;
         }
         if(c==arm)
         { printf("Entered no. is armstrong ");
         }
         else 
         { printf("Entered no. is not armstrong");
         }
        
}