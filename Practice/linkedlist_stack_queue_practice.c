#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
struct Node* print(struct Node**n)
{
    struct Node* newn=(*n);
    if(newn==NULL)
    {
        printf("NO element in the stack!!!\n");
    }
    while(newn != NULL )
    {
        printf("%d\n",newn->data);
        newn=newn->next;
    }
}
struct Node* push(struct Node** n,int ele)
{
    struct Node* newn2=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* current=(*n);
    newn2->data=ele;
    newn2->next=current;
    (*n)=newn2;

}
struct Node* pop(struct Node**n)
{

    if(*n!=NULL)
    {struct Node* current=(*n);
    (*n)=(*n)->next;
    free(current);
    }
    else
    {
        printf("Stack is empty!!\n");
    }
}
struct Node* enqueue(struct Node** n ,int ele)
{
    struct Node* newn3=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* current=(*n);
    newn3->data=ele;
    newn3->next=current;
    (*n)=newn3;
}
struct Node* dequeue(struct Node**n )
{
    struct Node *start=(*n),*prev;
    if((*n)->next!=NULL)
    {
        while(start->next!=NULL)
        {
            prev=start;
            start=start->next;
        }
        prev->next=NULL;
        free(start);

    }
    else
    {
        printf("No element in the queue!!!");
    }


}
void main()
{

    int p=1,ele1,choice,ele,firstele;
    struct Node* head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node*));
    printf("Enter the first element in the stack=\t");
    scanf("%d",&firstele);
    head->data=firstele;
    head->next=NULL;
    while(p!=0)
    {
    printf("\n1.Print\n2.Push\n3.Pop\n4.En-Queue\n9.Exit\nEnter your choice:\t");scanf("%d",&choice);
    switch(choice)
    {
        case 1:print(&head);break;
        case 2:printf("Enter the Number to push:\t");
               scanf("%d",&ele);
               push(&head,ele);
               break;
        case 3:pop(&head);
               break;
        case 4:printf("Enter the Number to En-queue:\t");
               scanf("%d",&ele1);
               enqueue(&head,ele1);
               break;
        case 5:dequeue(&head);break;
        case 9:p=0;break;
    }
    }

}
