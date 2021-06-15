#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node*display(struct Node**head)
{
    struct Node* ptr=(*head);
    if(ptr==NULL)
    {
        printf("Empty list found!!\n");
    }
    else
    {
        while(ptr->next!=(*head))
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}
struct Node* insertb(struct Node**head)
{
    struct Node *ptr=NULL,*temp;
    int ele;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the element to insert:\t");
    scanf("%d",&ele);
    ptr->data=ele;
    if((*head)!=NULL)
    {
        temp=(*head);
         while(temp->next!=(*head))
        {
            temp=temp->next;
        }
        ptr->next=(*head);
        temp->next=ptr;
        (*head)=ptr;
        printf("Element inserted at th beginning!!\n");

    }
    else
    {
        (*head)=ptr;
        ptr->next=(*head);
        printf("First element inserted!!\n");
    }

}
struct Node* inserte(struct Node**head)
{
    struct Node* temp=(*head),*ptr;
    int ele;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the element to insert at the end:\t");
    scanf("%d",&ele);
    ptr->data=ele;
    if(ptr!=NULL)
    {
        while(temp->next!=(*head))
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=(*head);
        printf("Element inserted at the endding!!\n");

    }
    else
    {
        (*head)=ptr;
        ptr->next=(*head);
        printf("First element inserted!!\n");
    }

}
void main()
{
    int choice;
    struct Node *head=NULL;
    while(choice!=9)
    {
    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specific position\n4.Delete at end\n5.Delete at beginning\n6.dlete at specific position\n7.Display\n9.Exit\n\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insertb(&head);break;
        case 2:inserte(&head);break;
        case 7:display(&head);break;
        case 9:choice=9;break;
    }
    }
}
