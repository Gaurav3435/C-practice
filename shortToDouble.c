#include<stdio.h>
void main()
{
    short a=10;
    double b=*(short*)&a;
    printf("%d\n",a);
    printf("%lf",b);
}
