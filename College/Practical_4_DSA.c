#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
int show(struct Node** head)//Gaurav Patil (A-33) DSA
{
    struct Node*temp=(*head);
    if(temp!=NULL)
    {
        while(temp)
        {
                printf("%d\n",temp->data);
                temp=temp->next;//Gaurav Patil (A-33) DSA

        }
    }
    else
    {
        printf("No element in the list\n");//Gaurav Patil (A-33) DSA
    }

}
int Delete(struct Node**head)
{
    struct Node* temp=(*head),*prev;
    int ele;
    printf("Enter the element to delete:\t");//Gaurav Patil (A-33) DSA
    scanf("%d",&ele);
    if(temp->data==ele)
    {
        (*head)=temp->next;
        printf("Element deleted!!\n");//Gaurav Patil (A-33) DSA
    }
    else if(head!=NULL)
    {
       while(temp)
        {

            if(temp->data==ele)
            {
                printf("Element Deleted!\n");//Gaurav Patil (A-33) DSA
                break;
            }
            prev=temp;
            temp=temp->next;

        }
        if(temp==NULL)
        {
            printf("No element found in the list\n");//Gaurav Patil (A-33) DSA
        }
        else
        {
            temp=prev;
            temp->next=temp->next->next;//Gaurav Patil (A-33) DSA

        }


    }



}
void main()
{
    int choice;
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*first=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fifth=(struct Node*)malloc(sizeof(struct Node));//Gaurav Patil (A-33) DSA
    struct Node*sixth=(struct Node*)malloc(sizeof(struct Node));

    head->data=1;
    head->next=first;

    first->data=2;//Gaurav Patil (A-33) DSA
    first->next=second;

    second->data=3;
    second->next=third;

    third->data=4;
    third->next=fifth;//Gaurav Patil (A-33) DSA

    fourth->data=5;
    fourth->next=fifth;

    fifth->data=6;
    fifth->next=sixth;

    sixth->data=7;
    sixth->next=NULL;
    printf("Gaurav Patil (A-33)  DSA  Practical-4\n");
    while(choice!=3)//Gaurav Patil (A-33) DSA
    {
            printf("\nChoose:\n1.Delete\n2.Show\n3.Exit\nEnter the Choice:\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:Delete(&head);break;
                case 2:show(&head);break;//Gaurav Patil (A-33) DSA
                case 3:break;
            }

    }




}
