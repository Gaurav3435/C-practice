#include<stdio.h>
#include<conio.h>
struct student
{
    int num;
    int denom;

};

struct student s1;

void main()
{
    s1.num=10;
    s1.denom=20;
    *(int*)&(s1.denom)=100;
    printf("%d\n",s1.num);
    printf("%d\n",s1.denom);
}
