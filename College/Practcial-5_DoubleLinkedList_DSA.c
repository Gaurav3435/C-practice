#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*prev;
    struct Node*next;
};

struct Node* display(struct Node** head)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=(*head);
    if(ptr==NULL)
    {
        printf("No element in the list");
    }
    else
    {
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    }
}

struct Node* laste(struct Node**head)
{
    int ele;
    printf("Enter the element to add at the end :\t");
    scanf("%d",&ele);
    struct Node*ptr =NULL,*previous=(*head);
    ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=ele;
    ptr->next=NULL;
    if((*head)==NULL)
    {
       ptr->next=NULL;
       ptr->prev=NULL;
       (*head)=ptr;
    }
    else
    {
    while(previous->next!=NULL)
    {
        previous=previous->next;
    }
    ptr->prev=previous;
    previous->next=ptr;
    }
}

struct Node* begine(struct Node** head)
{
    int ele;
    printf("Enter the element to add at the beginning:\t");
    scanf("%d",&ele);
    struct Node* ptr=NULL;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    if((*head)==NULL)
    {
        ptr->data=ele;
        ptr->prev=NULL;
        ptr->next=NULL;
        (*head)=ptr;
    }
    else
    {
        ptr->data=ele;
        ptr->prev=NULL;
        ptr->next=(*head);
        (*head)->prev=ptr;
        (*head)=ptr;
    }
    printf("\nNode inserted\n");
}

struct Node* specifice(struct Node** head)
{
    int ele,posi,p=0;
    printf("Enter the element you want to add:\t");
    scanf("%d",&ele);
    printf("Enter the position where you want to add:\t");
    scanf("%d",&posi);
    struct Node* ptr,*previous=(*head);
    ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=ele;
    while(p<posi)
    {
        p++;
        previous=previous->next;
    }
    (previous->prev)->next=ptr;
    ptr->prev=previous->prev;
    ptr->next=previous;
    previous->prev=ptr;
}

int deletion(struct Node** head)
{
    int ele,p=0;
    struct Node* current=(*head);
    printf("Enter the element to delete:\t");
    scanf("%d",&ele);
    while(current->data!=ele)
    {
        p++;
        current=current->next;
        if(current->next==NULL)
        {
            printf("Element not found\n");
            return 0;
        }
    }
    (current->prev)->next=current->next;
    (current->next)->prev=(current->prev);
    return 0;

}

struct Node* lastd(struct Node** head)
{
    struct Node* current=(*head);
    while(current->next!=NULL)
    {
        current=current->next;
    }
    (current->prev)->next=NULL;
    free(current);
}

struct Node* startd(struct Node**head)
{
    if((*head)->next!=NULL)
    {
        struct Node* current=(*head);
        (*head)=(*head)->next;
        free(current);
        (*head)->prev=NULL;
    }
    else if((*head)->next==NULL)
    {
        (*head)=NULL;
        free((*head));
    }
}

void main()
{
    int choice=0;
    struct Node* head=NULL;
    while(choice!=8)
    {
    printf("\n\n1.Insert at beginning\n2.Insert at last\n3.Add at the specific location\n4.deletion specific \n5.Delete at the end\n6.delete at the start\n7.Display\n8.Exit\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:begine(&head);break;
        case 2:laste(&head);break;
        case 3:specifice(&head);break;
        case 4:deletion(&head);break;
        case 5:lastd(&head);break;
        case 6:startd(&head);break;
        case 7:display(&head);break;
        case 8:choice=8;break;
    }
    }
}
