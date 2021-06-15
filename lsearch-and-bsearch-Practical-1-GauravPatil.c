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
            return i;//Gaurav Patil (A-54)  Practical 1 DAA
        }
    }
    return -1;
}
//Practical-1 BINARY SEARCH
int binarySearch(int a[],int low,int high,int key)
{
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(a[mid]<key)
     {
         low=mid+1;//Gaurav Patil (A-54)  Practical 1 DAA
     }
     else if(a[mid]>key)
     {
         high=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;
}

void main()
{
    int len,p=1,ele,i,search,choice,*array;
    printf("Gaurav Patil (A-54) Praticla-1  DAA\n");
    printf("Enter the Number of Element in the array:\t");
    scanf("%d",&len);
    array=malloc(len*sizeof(int));
    for (i=0;i<len;i++)
    {
        scanf("%d",&array[i]);   //Gaurav Patil (A-54)  Pratical 1  DAA
    }
    printf("Enter the element to search its position:\t");
    scanf("%d",&search);
    while(p!=0)
    {
    printf("\n1.Linear search\n2.Binary Search\nenter the Choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:ele=binarySearch(array,0,len-1,search);
    case 2:ele=lsearch(search,array,len);
    case 3:p=0;break;             //Gaurav Patil (A-54)  Practical 1 DAA

    }
    printf("The position of element is :\t%d\n",ele);
    }
}
