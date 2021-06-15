#include<stdio.h>
#include<stdlib.h>
//Gaurav Patil (A-54)
//Practical-1   LinearSearch
int lsearch(int search,int array[],int len)
{
    for (int i=0;i<len;i++)
    {
        if(array[i]==search)
        {
            return i;
        }
    }
    return -1;
}
void main()
{
    int len,ele,ele2,i,search,*array;
    printf("Enter the Number of Element in the array:\t");
    scanf("%d",&len);
    array=malloc(len*sizeof(int));
    for (i=0;i<len;i++)
    {
        scanf("%d",&array[i]);//Gaurav Patil (A-54) Pratical 1  DAA
    }
    printf("Enter the element to search its position:\t");
    scanf("%d",&search);
    ele=lsearch(search,array,len);
    printf("The position of element is :\t%d\n",ele);
}
