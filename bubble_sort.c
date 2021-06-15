#include<stdio.h>
#include<stdlib.h>
void show(int array[],int size)
{
    printf("\n");
    for (int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);//Gaurav Patil (A-54)
    }
}
void bubble_sort(int array[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];//Gaurav Patil (A-54)
                array[j+1]=temp;
            }
        }

    }
    printf("\nSorted Successully!!!\n");
}
void main()
{
    int size,p,*array,choice;
    printf("Enter the number of element in the array:\t");
    scanf("%d",&size);
    array=malloc(size*sizeof(int));//Gaurav PAtil
    for (int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    while(p!=0)
    {
    printf("Enter the Choice to \n1.Shown\n2.Sort the element using bubble sort technique\n3.Exit\nenter the key:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:show(array,size);
        break;
        case 2:bubble_sort(array,size);
        break;
        case 3: p=0;break;//Gaurav Patil
    }
    }
}
