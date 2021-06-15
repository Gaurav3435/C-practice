#include<stdio.h>
void main()
{
    int a=10;
    int* b=&a;
    int *pointer;
    printf("%d\n",*b);

    int array[]={1,2,3};
    printf("%d\n",*array);

    printf("%d\n",*(array+1));
    pointer=array+2;
    printf("%d\n",*pointer);



}
