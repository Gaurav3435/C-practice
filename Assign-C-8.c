#include<stdio.h>
void main()
{
    int a,sum=0;
    printf("Enter the Number:\t");
    scanf("%d",&a);
    while(a!=0)
    {
        sum=sum+a%10;
        a=a/10;

    }
    printf("The sum is :\t%d",sum);
}
