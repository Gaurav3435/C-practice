#include<stdio.h>
#include<conio.h>
void main()
{

    int a,num=0,i,b;
    printf("Enter the Number :\t");
    scanf("%d",&a);
    i=0;
    while(num<a)
    {
        b=i;
        num=b*b;
        i++;
    }
    printf("The Perfect square :\t%d\n",num);

}
