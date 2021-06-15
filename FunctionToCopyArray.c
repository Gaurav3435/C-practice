#include<stdio.h>
int* copy_array(int *f1,int *f2,int a)
{
    int i;
     for (i=0;i<4;i++)
    {
        printf("%d\n",*(f1+i));
    }
    for (i=0;i<a;i++)
    {
        f2[i]=f1[i];printf("%d",f2[i]);
    }
    return f2;
}


void main()
{
    int i;
    int array1[]={1,2,3,4};
    int array2[4];
    int *array3;
    array3=copy_array(array1,array2,4);
    for (i=0;i<4;i++)
    {
        printf("\n%d",*(array2+i));
    }
}
