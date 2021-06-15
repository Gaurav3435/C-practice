#include<stdio.h>
#include<string.h>
void show(int *a_p)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("The %d element is:\t%d\n",i+1,*(a_p+i));

    }
}
int search1(int *a_p,int key,int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        if(*(a_p+i)==key) return i+1;

    }
    return -1;

}

void* search2(void *a_p,void *key,int size,int elemsize)
{

    for (int i=0;i<size;i++)
    {
        void* address=(char*)a_p+i*sizeof(elemsize);
        if (memcmp(address,key,elemsize)==0)
        return address;

    }
    return NULL;

}
int cmpfn(void *k1,void*k2)
{
    int *p1=k1;
    int *p2=k2;

    return *p1-*p2;
}
int Strcmp(void *vp1,void *vp2)
{
    char *p1=*(char**)vp1;
    char *p2=*(char**)vp2;
    return strcmp(p1,p2);
}
void* search3(void *a_p,void *key,int size,int elemsize,int (*Strcmp)(void *,void*))    //int(*cmpfn)(void*,void*)
{

    for (int i=0;i<size;i++)
    {
        void* address=(char*)a_p+i*sizeof(elemsize);
        if (cmpfn(address,key)==0)
        {
        return address;
        }
    }
    return NULL;

}

void main1()
{
    int array[5];
    int key,i,press,*position;
    //int a;
    int *a;
    for(i=0;i<5;i++)
    {
        printf("Enter the %d element:\t",i+1);
        scanf("%d",&array[i]);
    }
    printf("Press 1 to show the element\nPress 2 to search the element\n");
    scanf("%d",&press);
    switch (press)
    {
        case 1: show(array);
        break;
        case 2:printf("Enter the element to search:\t");
               scanf("%d",&key);
               //a=search1(array,key,sizeof(array)/4);
               //a=search2(array,&key,sizeof(array)/sizeof(int),sizeof(int));
               a=search3(array,&key,sizeof(array)/sizeof(int),sizeof(int),cmpfn);
               printf("The element is found at %d position",*a);
        break;
    }
}

 void main()
 {
     char *notes[]={'Ga','Pa','Ro','Dj','aa'};
     char *favourite='Dj';
     char *found=search3(notes,&favourite,5,sizeof(char*),Strcmp);
     printf("Element found at position:\t%c\n",*found);


 }

