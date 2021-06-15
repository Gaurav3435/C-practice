#include<stdio.h>
void main()
{
    double a=97.1416;
    char ch =*(char*)&a;
    printf("%lf\n",a);
    printf("%c",ch);
}
