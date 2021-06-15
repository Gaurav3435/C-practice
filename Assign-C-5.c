#include<stdio.h>
void main()
{
    int a,c=0,b=0,sum=0,count=0;
    printf("\nTill which number you want to print Fibonacci Series\nEnter the Fibonacci Number:\t");
    scanf("%d",&a);
    while(count<a)
    {

        sum=c+b;
        printf("%d\t",sum);
        if (c==0 & b==0)
        {
            c=0;
            b=1;
        }
        c=b;
        b=sum;
        count++;
    }


}
