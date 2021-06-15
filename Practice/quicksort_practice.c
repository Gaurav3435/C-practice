#include<stdio.h>
#include<stdlib.h>
void show(int *array,int elen)
{
    for (int i=0;i<elen;i++)
    {
        printf("%d\n",*(array+i));
    }
}

void quicksort(int *array,int elen)
{
    int p,i,j;
    p=*array;
    i=*array;
    j=*(array+elen-1);
    if(i<j)
    {

        for(int i=*array;i<elen;i++)
        {
            if(i>p)
            {
                break;
            }
        }
        for(int j=*(array+elen-1);i>0;i--)
        {
            if(j<p)
            {
                break;
            }
        }
        printf("Hi1");
        int temp=*(array+i);
        *(array+i)=p;
        p=temp;
        quicksort(array,i);
        printf("Hi2");
        quicksort(array+i,j-i);
        printf("Hif");
    }
    else
    {
        int temp=*(array+i);
        *(array+i)=*(array+j);
        *(array+j)=temp;
    }

}
void main()
{
    int elen,*array,choice;
    printf("\nEnter the Number of element in the array:\t");
    scanf("%d",&elen);
    array=(int*)malloc(sizeof(int)*elen);
    printf("Enter the element in the array:\n");
    for(int i=0;i<elen;i++)
    {
        scanf("%d",array+i);
    }
    while(choice!=9)
    {
        printf("1.show\n9.Break\nEnter the choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:show(array,elen);break;\
            case 2:quicksort(array,elen);break;
            case 9:break;
        }
    }

}
