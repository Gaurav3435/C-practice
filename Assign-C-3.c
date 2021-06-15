#include<stdio.h>
void main()
{
    int a;
    printf("Enter the Number you want to classify as Even or Odd:\t");
    scanf("%d",&a);
    if (a%2==0) printf("Its an Even Number");
    else printf("Its an Odd Number");
}
