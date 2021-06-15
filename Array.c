#include<stdio.h>
void main()
{
    int array[2];
    array[1]=10;
    array[0]=11;
    array[2]=12;
    array[11]=100;
    array[-1]=111;
    printf("%d\n",array[0]);
    printf("%d\n",array[1]);
    printf("%d\n",array[2]);
    printf("%d\n",array[11]);
    printf("%d\n",array[-1]);

}
