#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
int printlist(struct Node *n)
{
    while(n!=NULL)
    {
        printf("%d\n",n->data);
        n=n->next;
    }
    return 0;
}
struct Node* append(struct Node** n,int ele)
{
    struct Node* add=NULL;
    struct Node* last=*n;
    add=(struct Node*)malloc(sizeof(struct Node*));
    add->data=ele;
    add->next=NULL;
    if((*n)->next==NULL)
    {
        last->next=add;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=add;
    return;
}
struct Node* push(struct Node**n,int ele)
{
    struct Node* prev=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* current=(*n);
    prev->data=ele;
    prev->next=current;
    (*n)=prev;
}
 struct Node* enterbet(struct Node**n,int m,int ele)
 {
     int p=0;

    if ((*n)== NULL)
	{
	printf("the given previous node cannot be NULL");
	return;
	}
     struct Node* newn=(struct Node*)malloc(sizeof(struct Node*));
     struct Node* current=(*n);
     while((p++)!=m)
     {
         current=current->next;
         p++;
     }
     newn->data=ele;
     newn->next=current->next;
     current->next=newn;
 }
 struct Node* deletell(struct Node**n,int posi)
 {
     int p=0;
     struct Node* del=(*n);
     while(p+1!=posi)
     {
         del=del->next;
         p++;
     }
      del->next=(del->next)->next;



 }
int main()
{
    int choice,ele,p=1,posi,key;
    struct Node* head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=3;
    head->next=NULL;
    while(p!=0)
    {
    printf("\n1.Append\n2.Push\n3.Insertbetween\n4.Delete\n5.print\n6.Exit\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the element to append:\t");
               scanf("%d",&ele);append(&head,ele);
               break;
        case 3:printf("Enter the element to append:\t");
               scanf("%d",&ele);
               printf("Enter the position to append:\t");
               scanf("%d",&posi);
               enterbet(&head,posi-1,ele);
               break;
        case 2:printf("Enter the element to push:\t");
               scanf("%d",&ele);push(&head,ele);
               break;
        case 4:printf("Enter the position of element to Delete:\t");
        scanf("%d",&key);
               deletell(&head,key);
               break;
        case 5:printlist(head);
               break;
        case 6:p=0;
               break;
    }
    }
    return 0;
}
