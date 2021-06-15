#include<stdio.h>
#include<stdlib.h>//Gaurav Patil (A-54) Practical -2 DAA
void show(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);
    }
}
void selectionsort(int array[],int size)
{
  for(int i=0;i<size;i++)
  {
      int lowest=i;
      for(int j=i+1;j<size;j++)
      {
          if(array[j]<array[lowest])
          lowest=j;

      }
      //swap
      int temp=array[i];
      array[i]=array[lowest];   //GAURAV PATIL (A_54)  Practical -2 DAA
      array[lowest]=temp;

  }
}
void main()
{
    int p,*array,size,choice;
    printf("Enter the size of array:\t");
    scanf("%d",&size);
    array=malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);  //Gaurav Patil (A-54) Practical -2 DAA
    }
    while(p!=0)
    {
    printf("\n1.show\n2.Selection sort\n3.Exit\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:show(array,size);break;
        case 2:selectionsort(array,size);break;
        case 3:p=0;break;              //Gaurav Patil (A-54) Practical -2 DAA
    }
    }
}
