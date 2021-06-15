#include<stdio.h>
#include<math.h>
void main()
{

    int a,b,remainder,sum=0;
    printf("To find the sum of enter digit \n Enter the Number::\t\n");
    scanf("%d",&a);
    while (a!=0)
    {
        remainder=a%10;
        sum=sum+pow(remainder,3);
        a=a/10;
    }
    printf("The sum of the digit is:\t %d",sum);



}
