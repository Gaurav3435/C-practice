#include<stdio.h>
int total(int a)
{
    int sum1=0,sum2=0,i;
    for(i=0;i<a+1;i++)
    {

    if(i%2==0)
    {sum1=sum1+i;
    }
    else
    {sum2=sum2+i;
    }

    }
    printf("The sum of Even Numbers:\t %d\n",sum1);
    printf("The sum of Odd Numbers:\t %d\n",sum2);

    return 0;

}


void main()
{
    int a;
    printf("\nTill which number you want to find the sum of Even and Odd\nEnter the Number:\n");
    scanf("%d",&a);
    total(a);
}
