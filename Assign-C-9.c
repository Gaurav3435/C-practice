#include<stdio.h>
int factorial(int a)
{
    if(a==0) return (1);

    return (a*factorial(a-1));
}
void main()
{
    int b,c;
    printf("Enter the Number for which you have to calculate the Factorial:\t\n");
    scanf("%d",&b);
    c=factorial(b);
    printf("The Factorial is :\t%d\n",c);
}
