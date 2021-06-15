#include<stdio.h>
#include<string.h>
struct student
{
    char *name;
    char suid[8];
    int numunits;
};
struct student pupils[4];
void main()
{
    int i;
    pupils[0].numunits=2;
    pupils[2].name=strdup("adam");
    pupils[3].name=pupils[0].suid+6;
    strcpy(pupils[1].suid,"40415xx");
    strcpy(pupils[3].name,"123456");
    pupils[7].suid[11]="A";


}
