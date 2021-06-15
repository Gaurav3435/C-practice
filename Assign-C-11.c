#include<stdio.h>
void main()
{
    int a,b=1,range=0,l=0,s=0;
    while(b==1)
    {
        printf("Enter the value  :\t");
        scanf("%d",&a);
        if (l==0){s=a;}
    if(a>=0)
    {
        printf("The Entered value:\t%d\n",a);
        range=range+1;
        printf("The Range is     :\t%d\n",range);
        if(a>l)
        {
            l=a;
        }
        printf("The Largest No.  :\t%d\n",l);
        if(s>a)
        {
            s=a;
        }
        printf("The smallest No. :\t%d\n",s);
    }
    else
    {
        break;
    }
    printf("\n");
    }

}
