#include<stdio.h>
#include<stdlib.h>
int binarysearch(int array[],int*elem,int key)
{
    int i;
    int left=0;
    int right=*elem-1;
    int middle;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(array[middle]==key){return middle;}
        else if(key>array[middle]){left=middle+1;}
        else if(key<array[middle]){right=middle-1;}
    }
    return -1;


}
void show(int array[],int *elen)
{
    printf("\n");
    for (int i=0;i<*elen;i++)
    {
        printf("%d\n",array[i]);
    }
}
void main()
{
    int p,*array,ele,key,size,*elen,choice,i;
    printf("Enter the number of element in the array:\t");
    scanf("%d",&size);
    elen=&size;
    array=malloc(size*sizeof(int));
    for (i=0;i<*elen;i++)
    {
        scanf("%d",&array[i]);
    }
    while(p!=0)
    {
    printf("\nEnter the Choice to:\n1.Show\n2.Binary Search\n3.Exit\nEnter the key:\t");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:show(array,elen);
        break;
        case 2:printf("Enter the key to find:\t");
        scanf("%d",&key);
        ele=binarysearch(array,elen,key);
        printf("The element is found at  position:\t%d\n",ele);
        break;
        case 3:p=0;
             break;

    }

    }


}
