#include<stdio.h>
void show(int array[])
{
    int i;
    for(i=0;i<6;i++)
    {
        printf("%d\n",array[i]);
    }
}
int insert(int array[])
{
    int l,m,i;
    printf("Enter the Element to insert :\t ");
    scanf("%d",&l);
    printf("Enter the Position to insert element:\t");
    scanf("%d",&m);
    for(i=0;i<6-m;i++)
    {
        array[5-i]=array[4-i];
    }
    array[m-1]=l;
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
        printf("Enter the choice \n1.Show\n2.Insert\n3.Exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:show(array);break;
            case 2:insert(array);break;
            case 3:p=0;break;
        }
    }


}
