#include<stdio.h>
void main()
{
    int i,j,b=1,a;
    printf("Enter the rows i structure:\t");
    scanf("%d",&a);
    for (j=0;j<a;j++)
    {
    for (i=0;i<(a-j);i++)
    {
        printf(" ");
    }
    for (i=0;i<j*2-1;i++)
    {
        printf("*");
        b=2;
    }
    printf("\n");
    }

}
