#include<stdio.h>
int total(int a)
{
    int i,sum=0;
    for(i=1;i<101;i++)
    {
        sum=sum+i;
    }
    return sum;
}

void main()
 {
     int a;
     printf("The sum of First 100 Numbers are as Follows:\n");
     a=total(100);
     printf("The sum is = %d\n",a);
 }
