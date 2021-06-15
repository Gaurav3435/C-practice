#include<stdio.h>
void show(int *array,int* len)
{
    int i;
    for(i=0;i<*len;i++)
    {
        printf("The element at %d position is:\t%d\n",i+1,*(array+i));
    }
}
void insert(int *array,int* len)
{
    int i,j;
    printf("In which position you want to insert the element:\t");
    scanf("%d",&i);
    printf("The element to insert is:\t");
    scanf("%d",&j);
    *(array+i-1)=j;
    printf("The element %d is inserted at %d position\n\n",i,*(array+i-1));
}

void rem(int *array,int* len)
{
    int i,j;
    printf("The position of element to delete is:\t");
    scanf("%d",&j);
    printf("The element %d is deleted at %d position\n\n",*(array+j-1),j);
    *len=*len-1;
    for(i=j;i<*len;i++)
    {
        *(array+i-1)=*(array+i);
    }
}

void main()
{
    int a[]={1,2,3,4,5};
    int key,length=5;
    int *len=&length;
    printf("This is the 5 element array\n\n");
    while(key!=4)
    {

    printf(" Press 1 To insert element\n Press 2 To delete element\n Press 3 to show array\n Press 4 To exit\n");
    scanf("%d",&key);
    printf("The key is :%d\n ",key);
    switch(key)
    {
        case 1:printf("You just trigger to insert the element:\n");
                insert(a,len);
                break;
        case 2:printf("You just trigger to delete the element:\n");
                rem(a,len);
                break;
        case 3:printf("The element in array are:\n");
                show(a,len);
                break;
        case 4:printf("You just triggered to exit the working!!!\n");
                key=4;
                break;
    }
    }

}
