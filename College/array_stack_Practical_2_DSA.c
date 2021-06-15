#include<stdio.h>
#include<stdlib.h>
//Gaurav Patil (A-54) DSA
int push(int *array,int *top,int *size)
{
    int ele;
    (*top)=(*top)+1;
    if((*top)>=(*size))
    {
        printf("Stack overflow !!!\n");     //Gaurav Patil (A-54) DSA
        (*top)--;
    }
    else
    {
    printf("\nEnter the element to push in stack:\t");
    scanf("%d",&ele);
    array[(*top)]=ele;
    printf("The last element %d is at position %d\n",ele,(*top)+1);//Gaurav Patil (A-54) DSA
    }
    return 0;
}
int show(int *array,int *top)                    //Gaurav Patil (A-54) DSA
{
    if((*top)==-1)
    {
        printf("no element in the array\n");
    }
    for(int i=(*top);i>=0;i--)
    {
        printf("%d\n",array[i]);//Gaurav Patil (A-54) DSA
    }
    return 0;
}
void palindrome(int arr[], int *n)
{
    int flag = 0;
    for (int i = 0; i <= (*n) / 2 && (*n)!= 0; i++) {
        if (arr[i] != arr[(*n) - i - 1]) {
            flag = 1;
            break;                      //Gaurav Patil (A-54) DSA
        }
    }
    if (flag == 1)
        printf("it is not a Not Palindrome\n");
    else
        printf("it is a Palindrome\n");         //Gaurav Patil (A-54) DSA
}
int pop(int*array,int *top)
{
    if((*top)==-1)
    {
        printf("Stack underflow!!!\n");
    }
    else                                         //Gaurav Patil (A-54) DSA
    {
        printf("The element %d is poped from %d position\n",array[(*top)],(*top)+1);
        (*top)--;

    }
    return 0;
}                                                 //Gaurav Patil (A-54) DSA
int peek(int *array,int *top,int*size)
{
    if((*top)!=-1 && (*top)<(*size)-1)
    {
        printf("The stack contain %d element \n",(*top)+1);         //Gaurav Patil (A-54) DSA
    }
    return 0;


}
int isFull(int *array,int*top,int*size)             //Gaurav Patil (A-54) DSA
{
    if((*top)>=(*size)-1)
    {
        printf("You cannot enter the element ,its full!!\n");
    }
    return 0;
}
int isEmpty(int *array,int*top,int*size)           //Gaurav Patil (A-54) DSA
{
    if((*top)==-1)
    {
        printf("The stack is empty ,you cannot remove element!!!\n");
    }
    return 0;
}                                 //Gaurav Patil (A-54) DSA

int main()
{
    int *array,p=1,choice,size,top=-1;;
    printf("Gaurav Patil A-54  DSA\n\n");
    printf("Enter the size of stack:\t");
    scanf("%d",&size);
    array=malloc(size*sizeof(int));
    while(p!=0)                              //Gaurav Patil (A-54) DSA
    {
    printf("\n1.Push\n2.Pop\n3.Implement palindrome check\n4.check overflow and underflow\n5.Show the stack\n6.Exit\nEnter the Choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:push(array,&top,&size);break;
        case 2:pop(array,&top);break;
        case 3:palindrome(array,&size);break;//Gaurav Patil (A-54) DSA
        case 4:isEmpty(array,&top,&size);isFull(array,&top,&size);peek(array,&top,&size);break;
        case 5:show(array,&top);break;
        case 6:p=0;break;                     //Gaurav Patil (A-54) DSA
    }
    }
    printf("Gaurav Patil A-54  DSA\n");
    return 0;
}
