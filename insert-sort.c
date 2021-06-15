#include<stdio.h>
#include<stdlib.h>   //Gaurav Patil (A-54) Practical -2 DAA
void show(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);
    }
}
void insertsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        scanf("%d",&array[i]);     //Gaurav Patil (A-54) Practical -2 DAA
    }
    while(p!=0)
    {
    printf("\n1.show\n2.insert sort\n3.Exit\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:show(array,size);break;
        case 2:insertsort(array,size);break;
        case 3:p=0;break;                //Gaurav Patil (A-54) Practical -2 DAA
    }
    }
}
