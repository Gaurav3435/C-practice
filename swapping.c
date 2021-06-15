#include<stdio.h>
void swap(int *i,int*j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void main()
{
    int i,j;
    scanf("%d%d",&i,&j);
    printf("Enter numbers are:%d %d\n",i,j);
    swap(&i,&j);
    printf("Enter numbers now:%d %d\n",i,j);
}
