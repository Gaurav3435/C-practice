#include<stdio.h>
#include<string.h>
void swap1(int *x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}
void swap2(void *vp1,void *vp2,int size)
{
    char buffer[size];
    memcpy(buffer,vp1,size);
    memcpy(vp1,vp2,size);
    memcpy(vp2,buffer,size);
}
void main1()
{
    int x;
    int y;
    printf("X=\t");
    scanf("%d",&x);
    printf("Y=\t");
    scanf("%d",&y);
    /*swap1(&x,&y);*/
    swap2(&x,&y,sizeof(x));
    printf("X=\t%d\nY=\t%d\n",x,y);
}
void main()
{
    char *p=strdup("Gurav");
    char *q=strdup("Patil");
    swap2(&p,&q,sizeof(char*));
    /*swap2(p,q,sizeof(char*));   This will swap the array not the pointer that store the address of the array*/
    printf("X=\t%c\nY=\t%c\n",*p,*q);
}
