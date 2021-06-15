#include<stdio.h>
void show(int array[])
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("%d\n",array[i]);
    }
}
int remov(int array[])
{
    int l,m,i;
    printf("Enter the Position to delete element:\t");
    scanf("%d",&m);
    m=m-1;
    for(i=m;i<5;i++)
    {
        array[i]=array[i+1];
    }
    return 0;
}
void main()
{
    int i,p,a,array[6];
    printf("Enter the element in array:\n");
    for (i=0;i<5;i++)
    {
      scanf("%d",&array[i]);
    }
    while(p!=0)
    {
        printf("Enter the choice \n1.Show\n2.Delete\n3.Exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:show(array);break;
            case 2:remov(array);break;
            case 3:p=0;break;
        }
    }


}
